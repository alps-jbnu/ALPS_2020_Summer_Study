#pragma once

#include "eSymbolType.h"
#include "Monster.h"

namespace rpg_extreme{
    class BossMonster final : public Monster {
    public:
        BossMonster(const int8_t x, const int8_t y, const std::string& name,
        const int16_t attack, const int16_t defense, const int16_t hp,
        const uint16_t exp);

        virtual char GetSymbol() const override;
        virtual bool IsBoss() const override;
    };
}