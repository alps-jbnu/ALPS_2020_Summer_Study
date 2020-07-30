#include "Map.h"

namespace rpg_extreme
{
    Map::Map(const uint8_t width, const uint8_t height,
             const std::vector<std::string> &mapData)
        : mWidth(width), mHeight(height), mItemBoxCount(0), mMonsterCount(0),
          mPlayer(nullptr), mBossMonsterPosX(0), mBossMonsterPosY(0)
    {
        mGameObjects.reserve(mHeight);
        for (int y = 0; y < mHeight; ++y)
        {
            auto rowVector = std::vector<std::vector<GameObject *>>();
            rowVector.reserve(mWidth);

            for (int x = 0; x < mWidth; ++x)
            {
                const char symbol = mapData[y][x];
                std::vector<GameObject *> objVector;
                switch (symbol)
                {
                    //TODO: 입력
                case eSymbolType::BLANK:
                    // objVector.push_back(new GameObject(x, y));
                    break;
                case eSymbolType::WALL:
                    objVector.push_back(new Wall(x, y));
                    break;
                case eSymbolType::ITEM_BOX:
                    objVector.push_back(new EquipmentBox(x, y, nullptr));
                    mItemBoxCount++;
                    break;
                case eSymbolType::SPIKE_TRAP:
                    objVector.push_back(new SpikeTrap(x, y));
                    break;
                case eSymbolType::MONSTER:
                    mMonsterCount++;
                    objVector.push_back(new Monster(x, y, "", 0, 0, 0, 0));
                    break;
                case eSymbolType::BOSS_MONSTER:
                    mMonsterCount++;
                    mBossMonsterPosY = y;
                    mBossMonsterPosX = x;
                    //TODO: BossMonster로 바뀌어야함
                    objVector.push_back(new Monster(x, y, "", 0, 0, 0, 0));
                    break;
                case eSymbolType::PLAYER:
                    mPlayer = new Player::Player(x, y);
                    objVector.push_back(mPlayer);
                    break;
                default:
                    assert(false);
                }
                rowVector.push_back(objVector);
            }
            mGameObjects.push_back(rowVector);
        }
    }

    Map::~Map() {
        Remove(mPlayer);
        delete mPlayer;

        for (auto& rowVector : mGameObjects) {
            for (auto& columnVector : rowVector) {
                for(auto& objectPtr : columnVector) {
                    delete objectPtr;
                }
            }
        }
    }

    size_t Map::GetItemBoxCount() const {
        return mItemBoxCount;
    }

    size_t Map::GetMonsterCount() const {
        return mMonsterCount;
    }

    void Map::Spawn(GameObject* const gameObject) {
        //TODO: mGameObjects에 gameObject를 추가합니다.
        if(gameObject->IsCharacter()) {
            switch(gameObject->GetSymbol()) {
            case eSymbolType::BOSS_MONSTER:
            case eSymbolType::MONSTER:
                Monster* monster = dynamic_cast<Monster *>(gameObject);
                if(monster) {
                    monster->FillUpHp();
                    mGameObjects[monster->GetY()][monster->GetX()].push_back(monster);
                }
                break;
            case eSymbolType::PLAYER:
                Player* player = dynamic_cast<Player *>(gameObject);
                if(player) {
                    player->FillUpHp();
                    mGameObjects[player->GetInitY()][player->GetInitX()].push_back(player);
                }
                break;
            }
        }
        else { // Character가 아닌 case
            assert(false);
        }
    }

    bool Map::Remove(GameObject* const gameObject) {
        for(auto fitr = mGameObjects.begin(); fitr != mGameObjects.end(); fitr++) {
            for(auto sitr = fitr->begin(); sitr != fitr->end(); sitr++) {
                for(auto titr = sitr->begin(); titr != sitr->end(); titr++) {
                    if(gameObject == *titr)
                        sitr->erase(titr);
                }
            }
        }
        return false;
    }

    size_t Map::GetGameObjectCount(const int8_t x, const int8_t y) const {
        return mItemBoxCount + mMonsterCount + 1;
    }

    GameObject* Map::GetGameObject(const int8_t x, const int8_t y, const uint8_t index) const{
        return mGameObjects[y][x][index];
    }

    bool Map::IsPassable(const int8_t x, const int8_t y) const {
        if(x > mWidth || x < 1 || y > mHeight || y < 1) return false;
        for(auto itr : mGameObjects[y][x])
            if(itr->IsWall())
                return false;
        return true;
    }

    Player* Map::GetPlayer() const {
        return mPlayer;
    }

    std::string Map::ToString() const {
        std::stringstream ss;
        
        for(int y = 0; y < mHeight; ++y) {
            for(int x = 0; x < mWidth; ++x) {
                ss << '.';
            }
            ss << '\n';
        }
        return ss.str();
    }

    int8_t Map::GetBossMonsterPosX() const {
        return mBossMonsterPosX;
    }

    int8_t Map::GetBossMonsterPosY() const {
        return mBossMonsterPosY;
    }
} 