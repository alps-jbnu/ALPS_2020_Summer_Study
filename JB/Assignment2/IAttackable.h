#pragma once

#include "Character.h"

namespace rpg_extreme {
    class IAttackable {
    public:
        virtual bool IsAttackable() const = 0;
        virtual void AttackTo(Character* const character) = 0;
    };
}