#include "Game.h"
#include "Player.h"

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

    bool Player::IsAttackedable() cosnt {
        return true;
    }

    void Player::AttackTo(Character* const character) {
        Monster* monster = static_cast<Monster*>(character);
        //TODO: 몬스터 공격
        
    }

    void Player::OnAttacked(GameObject* const gameObject, const int16_t damage) {
        this->mHp -= damage;
        //TODO: 생존여부 확인 및 처리
    }

    void Player::MoveTo(const int8_t x, const int8_t y) {
        Map& map = Game::GetInstance().GetMap();
        //TODO: Game.h 작성 이후 작성
    }

    void Player::MoveLeft() {
        //TODO: 맵의 범위를 벗어나는 지 체크
        this->mX++;
    }

    void Player::MoveRight() {
        //TODO: 범위 체크
        this->mX--;
    }
    
    void Player::MoveUp() {
        //TODO: 범위 체크
        this->mY--;
    }

    void Player::MoveDown() {
        //TODO: 범위 체크
        this.mY++;
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
        //IsAccessoryEquippable 호출 후 호출해야함
        mAccessories.push_back(accessory);
    }

    void Player::UnequipReincarnationAccessory() {
        //TODO: Accessory class 정의 후 REINCARNATION 속성 장신구(Accessory) 파괴
        //std::find() 이용
    }

    void Player::EquipWeapon(Weapon* const weapon) {
        delete mWeapon;
        mWeapon = weapon;
    }

    bool Player::IsAccessoryEquippable(const Accessory* const accessory) const {
        if(mAccessories.size() + 1 >= Player::ACCESSORY_SLOT_CAPACITY)
            return false;
        //TODO: Accessory class 정의 후 중복되는 효과가 있으면 스킵하도록 코드 작성
        return false;
    }

    bool Player::HasAccessoryEffect(const eAccessoryEffectType accessoryEffectType) const {
        //TODO: Accessory class 정의 후 COURAGE 효과가 있는 장신구(accessory)가 mAccessories에 존재하는 경우
        //
    }

    void Player::SetCourageBuff() {
        
        mbCourageBuff = true;
    }

    void Player::SetHunterBuff() {
        mbHunterBuff = true;
    }

    uint16_t Player::GetLevel() const {
        return mLevel;
    }

    uint16_t Player::GetMaxExp() const {
        return 5 * mLevel;
    }

    uint16_t Player::GetMaxHp() const {
        return mMaxHp;
    }

    int16_t Player::GetWeaponAttack() const {
        // Weapon class 정의 후, weapon 공격력 반환
        return 0;
    }

    int16_t Player::GetArmorDefense() const {
        // Armor class 정의 후, armor 방어력 반환
        return 0;
    }

    int8_t Player::GetInitX() const {
        return mInitX;
    }

    int8_t Player::GetInitY() const {
        return mInitY;
    }
}