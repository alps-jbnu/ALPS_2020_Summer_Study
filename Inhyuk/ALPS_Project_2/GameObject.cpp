#include "GameObject.h"
 
namespace rpg_extreme
{
    GameObject::GameObject(const int8_t x, const int8_t y)
        : mX(x), mY(y)
    {
    }
 
    GameObject::~GameObject()
    {
    }
 
    int8_t GameObject::GetX() const
    {
        return mX;
    }
 
    int8_t GameObject::GetY() const
    {
        return mY;
    }
}
