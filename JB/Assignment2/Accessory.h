#pragma once

#include "Equipment.h"
#include "eAccessoryEffectType.h"

namespace rpg_extreme{
    class Accessory final : public Equipment {
    public:
        Accessory(const eAccessoryEffectType type);
        virtual bool IsArmor() const override;
        virtual bool IsAccessory() const override;
        virtual bool IsWeapon() const override;
        eAccessoryEffectType GetType() const;

    private:
        const eAccessoryEffectType mType;
    };
}