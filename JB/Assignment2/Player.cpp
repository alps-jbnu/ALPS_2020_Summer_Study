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
            int16_t weaponAttack = mWeapon ? GetWeaponAttack() : 0;
            if(mbCourageBuff) {
                if (mbHunterBuff)
                    monster->OnAttacked(this, (this->GetAttack() + weaponAttack) * 3);
                else
                    monster->OnAttacked(this, (this->GetAttack() + weaponAttack) * 2);
            }
            else
                monster->OnAttacked(this, this->GetAttack() + weaponAttack);
        }
    }

    void Player::OnAttacked(GameObject* const gameObject, const int16_t damage) {
        if(gameObject->IsSpikeTrap())
            this->mHp -= damage;
        else // Monster
        {
            int16_t armorDefense = mArmor ? GetArmorDefense() : 0;
            this->mHp -= max(1, damage - (this->GetDefense() + armorDefense));
        }
    }

    void Player::MoveTo(const int8_t x, const int8_t y) {
        Map& map = Game::GetInstance().GetMap();
        if(map.IsPassable(x, y)) {
            map.Remove(this);
            this->mX = x;
            this->mY = y;
            map.Spawn(this);
        }
    }

    void Player::MoveLeft() {
        Map& map = Game::GetInstance().GetMap();
        map.Remove(this);
        if(map.IsPassable(this->GetX()-1, this->GetY()))
            this->mX--;
        map.Spawn(this);
    }

    void Player::MoveRight() {
        Map& map = Game::GetInstance().GetMap();
        map.Remove(this);
        if(map.IsPassable(this->GetX()+1, this->GetY()))
            this->mX++;
        map.Spawn(this);
    }
    
    void Player::MoveUp() {
        Map &map = Game::GetInstance().GetMap();
        map.Remove(this);
        if(map.IsPassable(this->GetX(), this->GetY()-1))
            this->mY--;
        map.Spawn(this);
    }

    void Player::MoveDown() {
        Map &map = Game::GetInstance().GetMap();
        map.Remove(this);
        if (map.IsPassable(this->GetX(), this->GetY()+1))
            this->mY++;
        map.Spawn(this);
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
        auto findResult = std::find_if(mAccessories.begin(), mAccessories.end(),
            [](Accessory* item) {
                if (item == nullptr) return false;
                return item->GetType() == eAccessoryEffectType::REINCARNATION;
            }
        );
        if(findResult != mAccessories.end()) {
            mAccessories.erase(findResult);
        }
    }

    void Player::EquipWeapon(Weapon* const weapon) {
        delete mWeapon;
        mWeapon = weapon;
    }

    bool Player::IsAccessoryEquippable(const Accessory* const accessory) const {
        if(mAccessories.size() >= Player::ACCESSORY_SLOT_CAPACITY)
            return false;
        if(HasAccessoryEffect(accessory->GetType()))
            return false;

        return true;
    }

    bool Player::HasAccessoryEffect(const eAccessoryEffectType accessoryEffectType) const {
        auto findResult = std::find_if(mAccessories.begin(), mAccessories.end(), 
            [accessoryEffectType](Accessory* item) {
                if (item == nullptr) return false;
                return item->GetType() == accessoryEffectType;
            }
            );
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
        if (mWeapon == nullptr) return 0;
        return mWeapon->GetAttack();
    }

    int16_t Player::GetArmorDefense() const {
        if (mArmor == nullptr) return 0;
        return mArmor->GetDefense();
    }

    int8_t Player::GetInitX() const {
        return mInitX;
    }

    int8_t Player::GetInitY() const {
        return mInitY;
    }
}