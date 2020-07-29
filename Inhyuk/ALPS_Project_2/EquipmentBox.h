#pragma once
 
#include <cstdint>
 
#include "GameObject.h"
#include "Equipment.h"
#include "eSymbolType.h"
 
namespace rpg_extreme
{
    class EquipmentBox final : public GameObject
    {
    public:
        EquipmentBox(const int8_t x, const int8_t y, Equipment* equipment);
 
        virtual char GetSymbol() const override;
        virtual bool IsCharacter() const override;
        virtual bool IsEquipmentBox() const override;
        virtual bool IsWall() const override;
        virtual bool IsSpikeTrap() const override;
 
        Equipment* GetEquipment();
 
    private:
        Equipment* mEquipment;
    };
}
