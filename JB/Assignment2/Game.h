#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>

#include "Map.h"
#include "eSymbolType.h"
#include "Weapon.h"
#include "Armor.h"
#include "Accessory.h"
#include "SpikeTrap.h"
#include "Monster.h"
#include "BossMonster.h"

namespace rpg_extreme{
    class Game final {
    public:
        static Game& GetInstance();

        void Start();
        void Shudown();
        Map& GetMap() const;
        std::string GetResultToString() const;

    private:
        Game();
        ~Game();

        void openEquipmentBox(EquipmentBox* const equipmentBox);
        void battleWithBossMonster(BossMonster* const bossMonster);
        void battleWithMonster(Monster* const monster);
        void stepOnSpikeTrap(SpikeTrap* const spikeTrap);

        static Game* sInstance;

        Map* mMap;
        size_t mTurnCount;
        bool mbGameClear;
        std::string mPlayerKillerName;
    };
}