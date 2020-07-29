#include "EquipmentBox.h"
 
namespace rpg_extreme
{
    EquipmentBox::EquipmentBox(const int8_t x, const int8_t y, Equipment* equipment)
        : GameObject(x, y)
        , mEquipment(equipment)
    {
    }
 
    char EquipmentBox::GetSymbol() const
    {
        return 'B';
    }
 
    bool EquipmentBox::IsCharacter() const
    {
        return false;
    }
 
    bool EquipmentBox::IsEquipmentBox() const
    {
        return true;
    }
 
    bool EquipmentBox::IsWall() const
    {
        return false;
    }
 
    bool EquipmentBox::IsSpikeTrap() const
    {
        return false;
    }
 
    Equipment* EquipmentBox::GetEquipment()
    {
        Equipment* tmp = mEquipment;
        mEquipment = nullptr;
        return tmp;
    }
}
