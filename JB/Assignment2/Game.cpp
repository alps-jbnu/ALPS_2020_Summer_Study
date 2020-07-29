#include "Game.h"

namespace rpg_extreme{
    Game* Game::sInstance = nullptr;

    Game& Game::GetInstance() {
        if(sInstance == nullptr) {
            sInstance = new Game();
        }
        return *sInstance;
    }

    void Game::Start() {
        // Input Map data
        int width;
        int height;
        std::vector<std::string> mapData;
        
        std::cin >> height >> width;
        mapData.reserve(height);

        for(int i = 0; i < height; i++) {
            std::string line;
            std::cin >> line;
            mapData.push_back(line);
        }

        mMap = new Map(width, height, mapData);

        // Input moveCommand data
        std::string moveCommand;
        std::cin >> moveCommand;

        // Input monster data
        size_t monsterCount = mMap->GetMonsterCount();
        for(size_t i = 0; i < monsterCount; i++) {
            int y;
            int x;
            std::string name;
            int attack;
            int defense;
            int maxHp;
            int exp;

            std::cin >> y >> x >> name >> attack >> defense >> maxHp >> exp;

            --y;
            --x;
        }

        // Input equipment data
        size_t itemBoxCount = mMap->GetItemBoxCount();
        for(size_t i = 0; i < itemBoxCount; i++) {
            int y;
            int x;
            char equipmentSymbolType;

            std::cin >> y >> x >> equipmentSymbolType;

            --y;
            --x;
            switch(equipmentSymbolType) {
            case eSymbolType::WEAPON:
                int attack;
                std::cin >> attack;
                break;
            case eSymbolType::ARMOR:
                int defense;
                std::cin >> defense;
                break;
            case eSymbolType::ACCESSORY:
                char type[3];
                std::cin >> type;
                break;
            default:
                assert(false);
            }
        }

        Player* player = mMap->GetPlayer();

        size_t moveCommandSize = moveCommand.length();
        for(mTurnCount = 0; mTurnCount < moveCommandSize; ++mTurnCount) {
            char d = moveCommand[mTurnCount];
            switch (d)
            {
            case 'L':
                /* code */
                break;
            case 'R':

                break;
            case 'U':
            
                break;
            case 'D':

                break;
            default:
                assert(false);
            }
        }
    }

    void Game::Shudown() {
        delete sInstance;
    }

    Map& Game::GetMap() const {
        return *mMap;
    }

    Game::Game() : mMap(nullptr), mTurnCount(0), mbGameClear(false) {}

    Game::~Game() {
        delete mMap;
    }

    void Game::battleWithBossMonster(BossMonster* const bossMonster) {
        Player* player = mMap->GetPlayer();
    }

    void Game::battleWithMonster(Monster* const monster) {
        Player* player = mMap->GetPlayer();
    }

    void Game::openEquipmentBox(EquipmentBox* const equipmentBox) {
        Player* player = mMap->GetPlayer();
    }

    void Game::stepOnSpikeTrap(SpikeTrap* const spikeTrap) {
        Player *player = mMap->GetPlayer();
    }

    std::string Game::GetResultToString() const {
        std::stringstream ss;

        Player *player = mMap->GetPlayer();

        ss << mMap->ToString();
        ss << "Passed Turns : " << 0 << '\n';
        ss << "LV : " << 1 << '\n';
        ss << "HP : " << 20 << '/' << 20 << '\n';
        ss << "ATT : " << 5 << '+' << 0 << '\n';
        ss << "DEF : " << 5 << '+' << 0 << '\n';
        ss << "EXP : " << 0 << '/' << 0 << '\n';

        if(mbGameClear) {
            ss << "YOU WIN!" << '\n';
        }
        else {
            if(player->IsAlive()) {
                ss << "Press any key to continue." << '\n';
            }
            else {
                ss << "YOU HAVE BEEN KILLED BY " << mPlayerKillerName << "..\n";
            }
        }

        ss << '\n';

        return ss.str();
    }
}