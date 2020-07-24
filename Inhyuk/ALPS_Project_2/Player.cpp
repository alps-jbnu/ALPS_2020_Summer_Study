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
        int16_t damage = GetAttack();
        monster->OnAttacked(this, damage);
    }
 
    void Player::OnAttacked(GameObject* const gameObject, const int16_t damage)
    {
        mHp -= std::max(1, damage-mDefense);
    }
 
    void Player::MoveTo(const int8_t x, const int8_t y)
    {
        Map& map = Game::GetInstance().GetMap();
    }
 
    void Player::MoveLeft()
    {
        mX--;
    }
 
    void Player::MoveRight()
    {
        mX++;
    }
 
    void Player::MoveUp()
    {
        mY--;
    }
 
    void Player::MoveDown()
    {
        mY++;
    }
 
    void Player::AddHp(const int16_t hp)
    {
        mHp += hp;
        if(mHp > mMaxHp)
            mHp = mMaxHp;
    }
 
    void Player::AddExp(uint16_t exp)
    {
        if(HasAccessoryEffect(eAccessoryEffectType::EXPERIENCE)) exp *= 1.2;
        mExp += exp;
        if(mExp >= 5 * mLevel){
            mLevel++;
            mMaxHp += 5;
            mAttack += 2;
            mDefense += 2;
            mHp = mMaxHp;
            mExp = 0;
        }
    }
 
    void Player::EquipArmor(Armor* const armor)
    {
        if(mArmor != nullptr){
            mDefense -= GetArmorDefense();
            delete mArmor;
        }
        mArmor = armor;
        mDefense += GetArmorDefense();
    }
 
    void Player::EquipAccessory(Accessory* const accessory)
    {
        if(IsAccessoryEquippable(accessory))
            mAccessories.push_back(accessory);
        
        if(accessory->GetType() == eAccessoryEffectType::COURAGE)
            SetCourageBuff();
        else if(accessory->GetType() == eAccessoryEffectType::HUNTER)
            SetHunterBuff();
        
    }
 
    void Player::UnequipReincarnationAccessory()
    {
       auto result = std::find(mAccessories.begin(), mAccessories.end(), [] (const Accessory& acc){
           return acc.GetType() == eAccessoryEffectType::REINCARNATION;
       });
       mAccessories.erase(result); //메모리 해제?
    }
 
    void Player::EquipWeapon(Weapon* const weapon)
    {
        if(mWeapon != nullptr){
            mAttack -= GetWeaponAttack();
            delete mWeapon;
        }
        mWeapon = weapon;
        mAttack += GetWeaponAttack();
    }
 
    bool Player::IsAccessoryEquippable(const Accessory* const accessory) const
    {
        if(mAccessories.size() - 1 == ACCESSORY_SLOT_CAPACITY)
            return false;
        if(HasAccessoryEffect(accessory->GetType()))
            return false;
        return true;
    }
 
    bool Player::HasAccessoryEffect(const eAccessoryEffectType accesoryEffectType) const
    {
        for(int i=0; i<mAccessories.size(); i++){
            if(mAccessories[i]->GetType() == accesoryEffectType)
                return true;
        }
        return false;
    }
 
    void Player::SetCourageBuff()
    {
        mbCourageBuff = true;
    }
 
    void Player::SetHunterBuff()
    {
        mbHunterBuff = true;   
    }
 
    uint16_t Player::GetLevel() const
    {
        return mLevel;
    }
 
    uint16_t Player::GetMaxExp() const
    {
        return 5 * mLevel;
    }
 
    int16_t Player::GetWeaponAttack() const
    {
        if(mWeapon == nullptr) return 0;

        return mWeapon->GetAttack();
    }
 
    int16_t Player::GetArmorDefense() const
    {
        if(mArmor == nullptr) return 0;
        return mArmor->GetDefense();
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

