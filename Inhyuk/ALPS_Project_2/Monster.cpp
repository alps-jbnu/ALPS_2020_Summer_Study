#include "Monster.h"
 
namespace rpg_extreme
{
    Monster::Monster(const int8_t x, const int8_t y, const std::string& name, const int16_t attack, const int16_t defense, const int16_t hp, const uint16_t exp)
        : Character(x, y, attack, defense, hp, exp)
        , mName(name)
    {
    }
 
    char Monster::GetSymbol() const
    {
        return '&';
    }
 
    bool Monster::IsPlayer() const
    {
        return false;
    }
 
    bool Monster::IsMonster() const
    {
        return true;
    }
 
    bool Monster::IsAttackable() const
    {
        return true;
    }
 
    bool Monster::IsAttackedable() const
    {
        return true;
    }
 
    void Monster::AttackTo(Character* const character)
    {
        Player* player = static_cast<Player*>(character);
        
    }
 
    void Monster::OnAttacked(GameObject* const gameObject, const int16_t damage)
    {
        //TODO
    }
 
    const std::string& Monster::GetName() const
    {
        return mName;
    }
 
    bool Monster::IsBoss() const
    {
        return false;
    }
}
