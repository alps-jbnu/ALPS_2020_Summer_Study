#include "BossMonster.h"

namespace rpg_extreme{
    BossMonster::BossMonster(const int8_t x, const int8_t y, const std::string& name,
    const int16_t attack, const int16_t defense, const int16_t hp, const uint16_t exp)
    : Monster(0, 0, name, 0, 0, 0, 0) {}

    char BossMonster::GetSymbol() const {
        return ' ';
    }

    bool BossMonster::IsBoss() const {
        return false;
    }
}