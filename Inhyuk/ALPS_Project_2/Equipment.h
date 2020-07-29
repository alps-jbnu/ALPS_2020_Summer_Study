#pragma once
 
#include <cstdint>
 
namespace rpg_extreme
{
    class Equipment
    {
    public:
        virtual bool IsArmor() const = 0;
        virtual bool IsAccessory() const = 0;
        virtual bool IsWeapon() const = 0;
    };
}
