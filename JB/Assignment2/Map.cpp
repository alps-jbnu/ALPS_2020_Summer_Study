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
                case eSymbolType::BLANK:
                    // objVector.push_back(GameObject(x, y))
                    break;
                case eSymbolType::WALL:

                    break;
                case eSymbolType::ITEM_BOX:
                        mItemBoxCount++;
                    break;
                case eSymbolType::SPIKE_TRAP:
                        
                    break;
                case eSymbolType::MONSTER:
                        mMonsterCount++;
                    break;
                case eSymbolType::BOSS_MONSTER:
                        mMonsterCount++;
                        mBossMonsterPosY = y;
                        mBossMonsterPosX = x;
                    break;
                case eSymbolType::PLAYER:
                    //TODO: mPlayer의 x, y좌표 삽입
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
        
    }

    bool Map::Remove(GameObject* const gameObject) {
        return false;
    }

    size_t Map::GetGameObjectCount(const int8_t x, const int8_t y) const {
        return 0;
    }

    GameObject* Map::GetGameObject(const int8_t x, const int8_t y, const uint8_t index) const{
        return nullptr;
    }

    boll Map::IsPassable(const int8_t x, const int8_t y) const {
        return true;
    }

    Player* Map::GetPlayer() const {
        return nullptr;
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