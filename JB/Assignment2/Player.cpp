#include "Game.h"
#include "Player.h"

namespace rpg_extreme{
    Player::Player(const int8_t x, const int8_t y)
    :Character(0, 0, 0, 0, 0, 0), mLevel(0), mWeapon(nullptr),
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
        return ' ';
    }

    bool Player::IsPlayer() const {
        return false;
    }

    bool Player::IsMonster() const {
        return false;
    }

    bool Player::IsAttackable() const {
        return false;
    }

    bool Player::IsAttackedable() cosnt {
        return false;
    }

    void Player::AttackTo(Character* const character) {
        Monster* monster = static_cast<Monster*>(character);
    }

    void Player::OnAttacked(GameObject* const gameObject, const int16_t damage) {

    }

    void Player::MoveTo(const int8_t x, const int8_t y) {
        Map& map = Game::GetInstance().GetMap();
    }

    void Player::MoveLeft() {

    }

    void Player::MoveRight() {

    }
    
    void Player::MoveUp() {

    }

    void Player::MoveDown() {

    }

    void Player::AddHp(const int16_t hp) {

    }

    void Player::AddExp(uint16_t exp) {

    }

    void Player::EquipArmor(Armor* const armor) {

    }

    void Player::EquipAccessory(Accessory* const accessory) {

    }

    void Player::UnequipReincarnationAccessory() {

    }

    void Player::EquipWeapon(Weapon* const weapon) {

    }

    bool Player::IsAccessoryEquippable(const Accessory* const accessory) const {
        return false;
    }
}