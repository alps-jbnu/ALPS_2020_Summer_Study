#include "Weapon.h"

namespace rpg_extreme{
    Weapon::Weapon(const int16_t attack)
    :mAttack(0) {
    }

    bool Weapon::IsArmor() const {
        return false;
    }

    bool Weapon::IsAccessory() const {
        return false;
    }

    bool Weapon::IsWeapon() const {
        return false;
    }

    int16_t Weapon::GetAttack() const {
        return 0;
    }
}