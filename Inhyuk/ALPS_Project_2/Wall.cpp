#include "Wall.h"
 
namespace rpg_extreme
{
    Wall::Wall(const int8_t x, const int8_t y)
        : GameObject(x, y)
    {
    }
 
    char Wall::GetSymbol() const
    {
        return '#';
    }
 
    bool Wall::IsCharacter() const
    {
        return false;
    }
 
    bool Wall::IsEquipmentBox() const
    {
        return false;
    }
 
    bool Wall::IsWall() const
    {
        return true;
    }
 
    bool Wall::IsSpikeTrap() const
    {
        return false;
    }
}
