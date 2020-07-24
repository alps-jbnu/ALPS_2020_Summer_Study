#pragma once
 
#include "GameObject.h"
#include "eSymbolType.h"
#include "Character.h"
#include "Player.h"
#include "IAttackable.h"
 
namespace rpg_extreme
{
    class SpikeTrap final : public GameObject, public IAttackable
    {
    public:
        SpikeTrap(const int8_t x, const int8_t y);
 
        virtual char GetSymbol() const override;
        virtual bool IsCharacter() const override;
        virtual bool IsEquipmentBox() const override;
        virtual bool IsWall() const override;
        virtual bool IsSpikeTrap() const override;
 
        virtual bool IsAttackable() const override;
        virtual void AttackTo(Character* const character) override;
 
    private:
        enum
        {
            DAMAGE = 5
        };
    };
}
