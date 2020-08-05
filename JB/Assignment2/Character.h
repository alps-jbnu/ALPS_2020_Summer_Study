#pragma once

#include "GameObject.h"

namespace rpg_extreme {
    class Character : public GameObject {
    public:
        virtual bool IsCharacter() const override;
        virtual bool IsEquipmentBox() const override;
        virtual bool IsWall() const override;
        virtual bool IsSpikeTrap() const override;

        virtual bool IsPlayer() const = 0;
        virtual bool IsMonster() const = 0;

        bool IsAlive() const;
        void FillUpHp();

        int16_t GetHp() const;
        int16_t GetMaxHp() const;
        int16_t GetAttack() const;
        int16_t GetDefense() const;
        uint16_t GetExp() const;
    protected:
        Character(const int8_t x, const int8_t y, const int16_t attack, const int16_t defense, const int16_t hp, const uint16_t exp);

        int16_t mHp;
        int16_t mMaxHp;
        int16_t mAttack;
        int16_t mDefense;
        uint16_t mExp;
    };
}