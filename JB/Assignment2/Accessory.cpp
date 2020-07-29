#include "Accessory.h"

namespace rpg_extreme{
    Accessory::Accessory(const eAccessoryEffectType type)
    :mType(type) {}

    bool Accessory::IsArmor() const {
        return false;
    }

    bool Accessory::IsAccessory() const {
        return false;
    }

    bool Accessory::IsWeapon() const {
        return false;
    }

    eAccessoryEffectType Accessory::GetType() const {
        return mType;
    }
}