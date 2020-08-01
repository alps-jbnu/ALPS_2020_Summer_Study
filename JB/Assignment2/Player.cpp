#include "Game.h"
#include "Player.h"
#define max(a, b) ((a) > (b) ? (a) : (b))

namespace rpg_extreme{
    Player::Player(const int8_t x, const int8_t y)
    :Character(x, y, 2, 2, 20, 0), mLevel(1), mWeapon(nullptr),
    mArmor(nullptr), mInitX(x), mInitY(y), mbCourageBuff(false), mbHunterBuff(false) {
        mAccessories.reserve(ACCESSORY_SLOT_CAPACITY);
    }

    Player::~Player() {
        delete mWeapon;
        delete mArmor;
        for(Accessory* accessory : mAccessories)
            delete accessory;
    }

    char Player::GetSymbol() const {
        return '@';
    }

    bool Player::IsPlayer() const {
        return true;
    }

    bool Player::IsMonster() const {
        return false;
    }

    bool Player::IsAttackable() const {
        return true;
    }

    bool Player::IsAttackedable() const {
        return true;
    }

    void Player::AttackTo(Character* const character) {
        if(character->IsMonster()) {
            Monster *monster = static_cast<Monster *>(character);
            if(mbCourageBuff)
                monster->OnAttacked(this, (this->GetAttack() + this->GetWeaponAttack()) * 2);
            else
                monster->OnAttacked(this, this->GetAttack() + this->GetWeaponAttack());
        }
    }

    void Player::OnAttacked(GameObject* const gameObject, const int16_t damage) {
        if(gameObject->IsSpikeTrap())
            this->mHp -= damage;
        else // Monster
            this->mHp -= max(1, damage - this->GetDefense());
    }

    void Player::MoveTo(const int8_t x, const int8_t y) {
        Map& map = Game::GetInstance().GetMap();
        if(map.IsPassable(x, y)) {
            map.Remove(this);
            map.Spawn(this);
        }
    }

    void Player::MoveLeft() {
        Map& map = Game::GetInstance().GetMap();
        if(map.IsPassable(this->GetX()-1, this->GetY()))
            this->mX--;
    }

    void Player::MoveRight() {
        Map& map = Game::GetInstance().GetMap();
        if(map.IsPassable(this->GetX()+1, this->GetY()))
            this->mX++;
    }
    
    void Player::MoveUp() {
        Map &map = Game::GetInstance().GetMap();
        if(map.IsPassable(this->GetX(), this->GetY()-1))
            this->mY--;
    }

    void Player::MoveDown() {
        Map &map = Game::GetInstance().GetMap();
        if (map.IsPassable(this->GetX(), this->GetY()+1))
            this->mY++;
    }

    void Player::AddHp(const int16_t hp) {
        if(mHp + hp > mMaxHp)
            mHp = mMaxHp;
        else 
            mHp += hp;
    }

    void Player::AddExp(uint16_t exp) {
        if(mExp + exp >= GetMaxExp()) {
            // 레벨업 성공한 경우
            mLevel++;
            mMaxHp += 5;
            mAttack += 2;
            mDefense += 2;
            FillUpHp();
            mExp = 0;
        }
        else mExp += exp;
    }

    void Player::EquipArmor(Armor* const armor) {
        delete mArmor;
        mArmor = armor;
    }

    void Player::EquipAccessory(Accessory* const accessory) {
        if(IsAccessoryEquippable(accessory))
            mAccessories.push_back(accessory);
    }

    void Player::UnequipReincarnationAccessory() {
        auto findResult = std::find(mAccessories.begin(), mAccessories.end(), Accessory(eAccessoryEffectType::REINCARNATION));
        if(findResult != mAccessories.end()) {
            mAccessories.erase(findResult);
        }
    }

    void Player::EquipWeapon(Weapon* const weapon) {
        delete mWeapon;
        mWeapon = weapon;
    }

    bool Player::IsAccessoryEquippable(const Accessory* const accessory) const {
        if(mAccessories.size() < Player::ACCESSORY_SLOT_CAPACITY)
            return false;
        if(HasAccessoryEffect(accessory->GetType()))
            return false;

        return true;
    }

    bool Player::HasAccessoryEffect(const eAccessoryEffectType accessoryEffectType) const {
        auto findResult = std::find(mAccessories.begin(), mAccessories.end(), Accessory(accessoryEffectType));
        if (findResult != mAccessories.end())
            return true;
        return false;
    }

    void Player::SetCourageBuff() {
        mbCourageBuff = !mbCourageBuff;
    }

    void Player::SetHunterBuff() {
        mbHunterBuff = !mbHunterBuff;
    }

    uint16_t Player::GetLevel() const {
        return mLevel;
    }

    uint16_t Player::GetMaxExp() const {
        return 5 * mLevel;
    }

    int16_t Player::GetWeaponAttack() const {
        return mWeapon->GetAttack();
    }

    int16_t Player::GetArmorDefense() const {
        return mArmor->GetDefense();
    }

    int8_t Player::GetInitX() const {
        return mInitX;
    }

    int8_t Player::GetInitY() const {
        return mInitY;
    }
}