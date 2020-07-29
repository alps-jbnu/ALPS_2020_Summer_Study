#include "GameObject.h"

namespace rpg_extreme {
    GameObject::GameObject(const int8_t x, const int8_t y)
        :mX(x), mY(y) {
            //TODO:  생성자의 초기화리스트를 완성하세요.
        }
    
    GameObject::~GameObject() {

    }
    
    int8_t GameObject::GetX() const {
        return mX;
    }

    int8_t GameObject::GetY() const {
        return mY;
    }
}