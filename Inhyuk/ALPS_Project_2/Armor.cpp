
#include "Armor.h"
 
namespace rpg_extreme
{
    Armor::Armor(const int16_t defense)
        : mDefense(defense)
    {
    }
 
    bool Armor::IsArmor() const
    {
        return true;
    }
 
    bool Armor::IsAccessory() const
    {
        return false;
    }
 
    bool Armor::IsWeapon() const
    {
        return false;
    }
    
    int16_t Armor::GetDefense() const
    {
        return mDefense;
    }
}