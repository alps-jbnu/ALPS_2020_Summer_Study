#include "Character.h"

namespace rpg_extreme {
    Character::Character(const int8_t x, const int8_t y, const int16_t attack, const int16_t defense, const int16_t hp, const uint16_t exp)
        : GameObject(x, y), mAttack(attack), mDefense(defense), mHp(hp), mMaxHp(hp), mExp(exp) {}
    
    bool Character::IsCharacter() const {
        return true;
    }

    bool Character::IsEquipmentBox() const {
        return false;
    }

    bool Character::IsWall() const {
        return false;
    }

    bool Character::IsSpikeTrap() const {
        return false;
    }

    bool Character::IsAlive() const {
        return (mHp > 0);
    }

    void Character::FillUpHp() { //체력 채우기
        mHp = mMaxHp;
    }

    int16_t Character::GetHp() const {
        return mHp;
    }

    int16_t Character::GetMaxHp() const {
        return mMaxHp;
    }

    int16_t Character::GetAttack() const {
        return mAttack;
    }

    int16_t Character::GetDefense() const {
        return mDefense;
    }

    uint16_t Character::GetExp() const {
        return mExp;
    }
}