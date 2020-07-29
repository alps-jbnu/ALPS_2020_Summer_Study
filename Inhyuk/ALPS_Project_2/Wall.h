#pragma once
 
#include "eSymbolType.h"
#include "GameObject.h"
 
namespace rpg_extreme
{
    class Wall final : public GameObject
    {
    public:
        Wall(const int8_t x, const int8_t y);
 
        virtual char GetSymbol() const override;
        virtual bool IsCharacter() const override;
        virtual bool IsEquipmentBox() const override;
        virtual bool IsWall() const override;
        virtual bool IsSpikeTrap() const override;
    };
}
