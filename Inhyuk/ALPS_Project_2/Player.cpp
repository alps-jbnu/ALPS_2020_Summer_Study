#include "Game.h"
#include "Player.h"
 
namespace rpg_extreme
{
    Player::Player(const int8_t x, const int8_t y)
        : Character(x, y, 2, 2, 20, 0)
        , mLevel(1)
        , mWeapon(nullptr)
        , mArmor(nullptr)
        , mInitX(x)
        , mInitY(y)
        , mbCourageBuff(false)
        , mbHunterBuff(false)
    {
        mAccessories.reserve(ACCESSORY_SLOT_CAPACITY);
    }
 
    Player::~Player()
    {
        delete mWeapon;
        delete mArmor;
        for (Accessory* accessory : mAccessories)
        {
            delete accessory;
        }
    }
 
    char Player::GetSymbol() const
    {
        return '@';
    }
 
    bool Player::IsPlayer() const
    {
        return true;
    }
 
    bool Player::IsMonster() const
    {
        return false;
    }
 
    bool Player::IsAttackable() const
    {
        return true;
    }
 
    bool Player::IsAttackedable() const
    {
        return true;
    }
 
    void Player::AttackTo(Character* const character)
    {
        Monster* monster = static_cast<Monster*>(character);

    }
 
    void Player::OnAttacked(GameObject* const gameObject, const int16_t damage)
    {
        mhp -= damage;
        if(mhp <= 0){
            //TODO
        }
    }
 
    void Player::MoveTo(const int8_t x, const int8_t y)
    {
        Map& map = Game::GetInstance().GetMap();
    }
 
    void Player::MoveLeft()
    {
 
    }
 
    void Player::MoveRight()
    {
 
    }
 
    void Player::MoveUp()
    {
 
    }
 
    void Player::MoveDown()
    {
 
    }
 
    void Player::AddHp(const int16_t hp)
    {
        mHp += hp;
        if(mHp > mMaxHp)
            mHp = mMaxHp;
    }
 
    void Player::AddExp(uint16_t exp)
    {
        mExp += exp;
        if(mExp >= 5 * mLevel){
            mLevel++;
            mExp = 0;
        }
    }
 
    void Player::EquipArmor(Armor* const armor)
    {
        if(mArmor != nullptr)
            delete mArmor;
        mArmor = armor;
    }
 
    void Player::EquipAccessory(Accessory* const accessory)
    {
        
    }
 
    void Player::UnequipReincarnationAccessory()
    {
 
    }
 
    void Player::EquipWeapon(Weapon* const weapon)
    {
 
    }
 
    bool Player::IsAccessoryEquippable(const Accessory* const accessory) const
    {
        return false;
    }
 
    bool Player::HasAccessoryEffect(const eAccessoryEffectType accesoryEffectType) const
    {
        return false;
    }
 
    void Player::SetCourageBuff()
    {
 
    }
 
    void Player::SetHunterBuff()
    {
 
    }
 
    uint16_t Player::GetLevel() const
    {
        return mLevel;
    }
 
    uint16_t Player::GetMaxExp() const
    {
        return 5 * mLevel;
    }
 
    int16_t Player::GetWeapOnAttacked() const
    {
        return 0;
    }
 
    int16_t Player::GetArmorDefense() const
    {
        return 0;
    }
 
    int8_t Player::GetInitX() const
    {
        return mInitX;
    }
 
    int8_t Player::GetInitY() const
    {
        return mInitY;
    }
}

