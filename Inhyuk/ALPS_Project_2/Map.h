#pragma once
 
#include <cstdint>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
 
#include "GameObject.h"
#include "Player.h"
#include "Monster.h"
#include "EquipmentBox.h"
#include "SpikeTrap.h"
#include "eSymbolType.h"
#include "Wall.h"
 
namespace rpg_extreme
{
    class Map final
    {
    public:
        Map(const uint8_t width, const uint8_t height, const std::vector<std::string>& mapData);
        ~Map();
 
        size_t GetItemBoxCount() const;
        size_t GetMonsterCount() const;
        void Spawn(GameObject* const gameObject);
        bool Remove(GameObject* const gameObject);
        size_t GetGameObjectCount(const int8_t x, const int8_t y) const;
        GameObject* GetGameObject(const int8_t x, const int8_t y, const uint8_t index) const;
        bool IsPassable(const int8_t x, const int8_t y) const;
        Player* GetPlayer() const;
        std::string ToString() const;
 
        int8_t GetBossMonsterPosX() const;
        int8_t GetBossMonsterPosY() const;
 
    private:
        const uint8_t mWidth;
        const uint8_t mHeight;
        size_t mItemBoxCount;
        size_t mMonsterCount;
        int8_t mBossMonsterPosX;
        int8_t mBossMonsterPosY;
 
        Player* mPlayer;
        std::vector<std::vector<std::vector<GameObject*>>> mGameObjects;
    };
}
