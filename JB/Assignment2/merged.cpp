#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <cstdint>
#include <vector>
#include <sstream>
#include <algorithm>
#define max(a, b) ((a) > (b) ? (a) : (b))
namespace rpg_extreme {
    class GameObject {
    public:
        virtual ~GameObject();

        virtual char GetSymbol() const = 0;
        virtual bool IsCharacter() const = 0;
        virtual bool IsEquipmentBox() const = 0;
        virtual bool IsWall() const = 0;
        virtual bool IsSpikeTrap() const = 0;

        int8_t GetX() const;
        int8_t GetY() const;

    protected:
        GameObject(const int8_t x, const int8_t y);

        int8_t mX;
        int8_t mY; 
    };
}
namespace rpg_extreme {
    enum eSymbolType {
        BLANK = '.',
        WALL = '#',
        ITEM_BOX = 'B',
        SPIKE_TRAP = '^',
        MONSTER = '&',
        BOSS_MONSTER = 'M',
        PLAYER = '@',
        WEAPON = 'W',
        ARMOR = 'A',
        ACCESSORY = 'O',
    };
}

namespace rpg_extreme {
    class Character : public GameObject {
    public:
        virtual bool IsCharacter() const override;
        virtual bool IsEquipmentBox() const override;
        virtual bool IsWall() const override;
        virtual bool IsSpikeTrap() const override;

        virtual bool IsPlayer() const = 0;
        virtual bool IsMonster() const = 0;

        bool IsAlive() const;
        void FillUpHp();

        int16_t GetHp() const;
        int16_t GetMaxHp() const;
        int16_t GetAttack() const;
        int16_t GetDefense() const;
        uint16_t GetExp() const;
    protected:
        Character(const int8_t x, const int8_t y, const int16_t attack, const int16_t defense, const int16_t hp, const uint16_t exp);

        int16_t mHp;
        int16_t mMaxHp;
        int16_t mAttack;
        int16_t mDefense;
        uint16_t mExp;
    };
}

namespace rpg_extreme{
    class Equipment{
    public:
        virtual bool IsArmor() const = 0;
        virtual bool IsAccessory() const = 0;
        virtual bool IsWeapon() const = 0;
    };
}

namespace rpg_extreme{
    class Weapon final : public Equipment {
    public:
        Weapon(const int16_t attack);
        virtual bool IsArmor() const;
        virtual bool IsAccessory() const;
        virtual bool IsWeapon() const;
        int16_t GetAttack() const;

    private:
        const int16_t mAttack;
    };
}

namespace rpg_extreme{
    class Armor final : public Equipment {
    public:
        Armor(const int16_t defense);

        virtual bool IsArmor() const override;
        virtual bool IsAccessory() const override;
        virtual bool IsWeapon() const override;
        int16_t GetDefense() const;

    private:
        const int16_t mDefense;
    };
}
namespace rpg_extreme{
    enum class eAccessoryEffectType{
        HP_REGENERATION,
        REINCARNATION,
        COURAGE,
        EXPERIENCE,
        DEXTERITY,
        HUNTER,
        CURSED
    };
}

namespace rpg_extreme{
    class Accessory final : public Equipment {
    public:
        Accessory(const eAccessoryEffectType type);
        virtual bool IsArmor() const override;
        virtual bool IsAccessory() const override;
        virtual bool IsWeapon() const override;
        eAccessoryEffectType GetType() const;

    private:
        const eAccessoryEffectType mType;
    };
}

namespace rpg_extreme {
    class IAttackable {
    public:
        virtual bool IsAttackable() const = 0;
        virtual void AttackTo(Character* const character) = 0;
    };
}

namespace rpg_extreme {
    class IAttackedable {
    public:
        virtual bool IsAttackedable() const = 0;
        virtual void OnAttacked(GameObject* const gameObject, const int16_t damage) = 0;
    };
}


namespace rpg_extreme{
    class Player final : public Character, public IAttackable, public IAttackedable {
    public:
        Player(const int8_t x, const int8_t y);
        ~Player();
        virtual char GetSymbol() const override;
        virtual bool IsPlayer() const override;
        virtual bool IsMonster() const override;

        virtual bool IsAttackable() const override;
        virtual bool IsAttackedable() const override;
        virtual void AttackTo(Character* const character) override;
        virtual void OnAttacked(GameObject* const gameObject, const int16_t damage) override;

        void MoveTo(const int8_t x, const int8_t y);
        void MoveLeft();
        void MoveRight();
        void MoveUp();
        void MoveDown();

        void AddHp(const int16_t hp);
        void AddExp(uint16_t exp);

        void EquipArmor(Armor* const armor);
        void EquipAccessory(Accessory* const accessory);
        void UnequipReincarnationAccessory();
        void EquipWeapon(Weapon* const weapon);

        bool IsAccessoryEquippable(const Accessory* const accessory) const;
        bool HasAccessoryEffect(const eAccessoryEffectType accessoryEffectType) const;

        void SetCourageBuff();
        void SetHunterBuff();

        uint16_t GetLevel() const;
        uint16_t GetMaxExp() const;
        int16_t GetWeaponAttack() const;
        int16_t GetArmorDefense() const;

        int8_t GetInitX() const;
        int8_t GetInitY() const;

    private:
        enum {
            ACCESSORY_SLOT_CAPACITY = 4
        };

        uint16_t mLevel;
        Weapon* mWeapon;
        Armor* mArmor;
        std::vector<Accessory*> mAccessories;

        bool mbCourageBuff;
        bool mbHunterBuff;

        const int8_t mInitX;
        const int8_t mInitY;
    };
}


namespace rpg_extreme{
    class Monster : public Character, public IAttackable, public IAttackedable {
    public:
        Monster(const int8_t x, const int8_t y, const std::string& name,
        const int16_t attack, const int16_t defense, const int16_t hp,
        const  uint16_t exp);

        virtual char GetSymbol() const override;
        virtual bool IsPlayer() const override;
        virtual bool IsMonster() const override;

        virtual bool IsAttackable() const override;
        virtual bool IsAttackedable() const override;
        virtual void AttackTo(Character* const character) override;
        virtual void OnAttacked(GameObject* const gameObject, const int16_t damage) override;

        const std::string& GetName() const;
        virtual bool IsBoss() const;

    protected:
        std::string mName;
    };
 }

namespace rpg_extreme{
    class BossMonster final : public Monster {
    public:
        BossMonster(const int8_t x, const int8_t y, const std::string& name,
        const int16_t attack, const int16_t defense, const int16_t hp,
        const uint16_t exp);

        virtual char GetSymbol() const override;
        virtual bool IsBoss() const override;
    };
}


namespace rpg_extreme{
    class EquipmentBox final : public GameObject {
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

namespace rpg_extreme{
    class SpikeTrap final : public GameObject, public IAttackable {
    public:
        SpikeTrap(const int8_t x, const int8_t y);

        virtual char GetSymbol() const override;
        virtual bool IsCharacter() const override;
        virtual bool IsEquipmentBox() const override;
        virtual bool IsWall() const override;
        virtual bool IsSpikeTrap() const override;

        virtual bool IsAttackable() const override;
        virtual void AttackTo(Character* const character) override;
    
    private:
        enum{
            DAMAGE = 5
        };
    };
}

namespace rpg_extreme{
    class Wall final : public GameObject {
    public:
        Wall(const int8_t x, const int8_t y);

        virtual char GetSymbol() const override;
        virtual bool IsCharacter() const override;
        virtual bool IsEquipmentBox() const override;
        virtual bool IsWall() const override;
        virtual bool IsSpikeTrap() const override;
    };
}

namespace rpg_extreme {
    class Map final {
    public:
        Map(const uint8_t width, const uint8_t height,
        const std::vector<std::string>& mapData);
        ~Map();

        size_t GetItemBoxCount() const;
        size_t GetMonsterCount() const;
        void Spawn(GameObject* const gameObject);
        bool Remove(GameObject* const gameObject);
        size_t GetGameObjectCount(const int8_t x, const int8_t y) const;
        GameObject* GetGameObject(const int8_t x, const int8_t y, const
        uint8_t index) const;
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


namespace rpg_extreme{
    class Game final {
    public:
        static Game& GetInstance();

        void Start();
        void Shutdown();
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
namespace rpg_extreme {
    Character::Character(const int8_t x, const int8_t y, const int16_t attack, const int16_t defense, const int16_t hp, const uint16_t exp)
        : GameObject(x, y), mAttack(attack), mDefense(defense), mHp(hp), mMaxHp(hp), mExp(exp) {}
    
    bool Character::IsCharacter() const {
        return true;
    }

    bool Character::IsEquipmentBox() const {
        return false;
    }

    bool Character::IsWall() const {
        return false;
    }

    bool Character::IsSpikeTrap() const {
        return false;
    }

    bool Character::IsAlive() const {
        return (mHp > 0);
    }

    void Character::FillUpHp() { //체력 채우기
        mHp = mMaxHp;
    }

    int16_t Character::GetHp() const {
        return mHp;
    }

    int16_t Character::GetMaxHp() const {
        return mMaxHp;
    }

    int16_t Character::GetAttack() const {
        return mAttack;
    }

    int16_t Character::GetDefense() const {
        return mDefense;
    }

    uint16_t Character::GetExp() const {
        return mExp;
    }
}
namespace rpg_extreme{
    Weapon::Weapon(const int16_t attack)
    :mAttack(attack) {
    }

    bool Weapon::IsArmor() const {
        return false;
    }

    bool Weapon::IsAccessory() const {
        return false;
    }

    bool Weapon::IsWeapon() const {
        return true;
    }

    int16_t Weapon::GetAttack() const {
        return mAttack;
    }
}
namespace rpg_extreme{
    Armor::Armor(const int16_t defense)
    : mDefense(defense) {}
    
    bool Armor::IsArmor() const {
        return true;
    }

    bool Armor::IsAccessory() const {
        return false;
    }

    bool Armor::IsWeapon() const {
        return false;
    }

    int16_t Armor::GetDefense() const {
        return mDefense;
    }
}
namespace rpg_extreme{
    Accessory::Accessory(const eAccessoryEffectType type)
    :mType(type) {}

    bool Accessory::IsArmor() const {
        return false;
    }

    bool Accessory::IsAccessory() const {
        return true;
    }

    bool Accessory::IsWeapon() const {
        return false;
    }

    eAccessoryEffectType Accessory::GetType() const {
        return mType;
    }
}

namespace rpg_extreme{
    Player::Player(const int8_t x, const int8_t y)
    :Character(x, y, 2, 2, 20, 0), mLevel(1), mWeapon(nullptr),
    mArmor(nullptr), mInitX(x), mInitY(y), mbCourageBuff(false), mbHunterBuff(false) {
        mAccessories.reserve(ACCESSORY_SLOT_CAPACITY);
    }

    Player::~Player() {
        delete mWeapon;
        delete mArmor;
        for(Accessory* accessory : mAccessories)
            delete accessory;
    }

    char Player::GetSymbol() const {
        return '@';
    }

    bool Player::IsPlayer() const {
        return true;
    }

    bool Player::IsMonster() const {
        return false;
    }

    bool Player::IsAttackable() const {
        return true;
    }

    bool Player::IsAttackedable() const {
        return true;
    }

    void Player::AttackTo(Character* const character) {
        if(character->IsMonster()) {
            Monster *monster = static_cast<Monster *>(character);
            int16_t weaponAttack = mWeapon ? GetWeaponAttack() : 0;
            if(mbCourageBuff) {
                if (mbHunterBuff)
                    monster->OnAttacked(this, (this->GetAttack() + weaponAttack) * 3);
                else
                    monster->OnAttacked(this, (this->GetAttack() + weaponAttack) * 2);
            }
            else
                monster->OnAttacked(this, this->GetAttack() + weaponAttack);
        }
    }

    void Player::OnAttacked(GameObject* const gameObject, const int16_t damage) {
        if(gameObject->IsSpikeTrap())
            this->mHp -= damage;
        else // Monster
        {
            int16_t armorDefense = mArmor ? GetArmorDefense() : 0;
            this->mHp -= max(1, damage - (this->GetDefense() + armorDefense));
        }
    }

    void Player::MoveTo(const int8_t x, const int8_t y) {
        Map& map = Game::GetInstance().GetMap();
        if(map.IsPassable(x, y)) {
            map.Remove(this);
            this->mX = x;
            this->mY = y;
            map.Spawn(this);
        }
    }

    void Player::MoveLeft() {
        Map& map = Game::GetInstance().GetMap();
        map.Remove(this);
        if(map.IsPassable(this->GetX()-1, this->GetY()))
            this->mX--;
        map.Spawn(this);
    }

    void Player::MoveRight() {
        Map& map = Game::GetInstance().GetMap();
        map.Remove(this);
        if(map.IsPassable(this->GetX()+1, this->GetY()))
            this->mX++;
        map.Spawn(this);
    }
    
    void Player::MoveUp() {
        Map &map = Game::GetInstance().GetMap();
        map.Remove(this);
        if(map.IsPassable(this->GetX(), this->GetY()-1))
            this->mY--;
        map.Spawn(this);
    }

    void Player::MoveDown() {
        Map &map = Game::GetInstance().GetMap();
        map.Remove(this);
        if (map.IsPassable(this->GetX(), this->GetY()+1))
            this->mY++;
        map.Spawn(this);
    }

    void Player::AddHp(const int16_t hp) {
        if(mHp + hp > mMaxHp)
            mHp = mMaxHp;
        else 
            mHp += hp;
    }

    void Player::AddExp(uint16_t exp) {
        if(mExp + exp >= GetMaxExp()) {
            // 레벨업 성공한 경우
            mLevel++;
            mMaxHp += 5;
            mAttack += 2;
            mDefense += 2;
            FillUpHp();
            mExp = 0;
        }
        else mExp += exp;
    }

    void Player::EquipArmor(Armor* const armor) {
        delete mArmor;
        mArmor = armor;
    }

    void Player::EquipAccessory(Accessory* const accessory) {
        if(IsAccessoryEquippable(accessory))
            mAccessories.push_back(accessory);
    }

    void Player::UnequipReincarnationAccessory() {
        auto findResult = std::find_if(mAccessories.begin(), mAccessories.end(),
            [](Accessory* item) {
                if (item == nullptr) return false;
                return item->GetType() == eAccessoryEffectType::REINCARNATION;
            }
        );
        if(findResult != mAccessories.end()) {
            mAccessories.erase(findResult);
        }
    }

    void Player::EquipWeapon(Weapon* const weapon) {
        delete mWeapon;
        mWeapon = weapon;
    }

    bool Player::IsAccessoryEquippable(const Accessory* const accessory) const {
        if(mAccessories.size() >= Player::ACCESSORY_SLOT_CAPACITY)
            return false;
        if(HasAccessoryEffect(accessory->GetType()))
            return false;

        return true;
    }

    bool Player::HasAccessoryEffect(const eAccessoryEffectType accessoryEffectType) const {
        auto findResult = std::find_if(mAccessories.begin(), mAccessories.end(), 
            [accessoryEffectType](Accessory* item) {
                if (item == nullptr) return false;
                return item->GetType() == accessoryEffectType;
            }
            );
        if (findResult != mAccessories.end())
            return true;
        return false;
    }

    void Player::SetCourageBuff() {
        mbCourageBuff = !mbCourageBuff;
    }

    void Player::SetHunterBuff() {
        mbHunterBuff = !mbHunterBuff;
    }

    uint16_t Player::GetLevel() const {
        return mLevel;
    }

    uint16_t Player::GetMaxExp() const {
        return 5 * mLevel;
    }

    int16_t Player::GetWeaponAttack() const {
        if (mWeapon == nullptr) return 0;
        return mWeapon->GetAttack();
    }

    int16_t Player::GetArmorDefense() const {
        if (mArmor == nullptr) return 0;
        return mArmor->GetDefense();
    }

    int8_t Player::GetInitX() const {
        return mInitX;
    }

    int8_t Player::GetInitY() const {
        return mInitY;
    }
}
namespace rpg_extreme{
    Monster::Monster(const int8_t x, const int8_t y, const std::string& name,
    const int16_t attack, const int16_t defense, const int16_t hp, const uint16_t exp)
    : Character(x, y, attack, defense, hp, exp), mName(name) {}

    char Monster::GetSymbol() const {
        return '&';
    }

    bool Monster::IsPlayer() const {
        return false;
    }

    bool Monster::IsMonster() const {
        return true;
    }

    bool Monster::IsAttackable() const {
        return true;
    }

    bool Monster::IsAttackedable() const {
        return true;
    }

    void Monster::AttackTo(Character* const character) {
        if(character->IsPlayer()) {
            Player *player = static_cast<Player *>(character);
            player->OnAttacked(this, this->GetAttack());
        }
    }

    void Monster::OnAttacked(GameObject* const gameObject, const int16_t damage) {
        mHp -= max(1, (damage - mDefense));
    }

    const std::string& Monster::GetName() const {
        return mName;
    }

    bool Monster::IsBoss() const {
        return false;
    }
}
namespace rpg_extreme{
    BossMonster::BossMonster(const int8_t x, const int8_t y, const std::string& name,
    const int16_t attack, const int16_t defense, const int16_t hp, const uint16_t exp)
    : Monster(x, y, name, attack, defense, hp, exp) {}

    char BossMonster::GetSymbol() const {
        return 'M';
    }

    bool BossMonster::IsBoss() const {
        return true;
    }
}
namespace rpg_extreme{
    EquipmentBox::EquipmentBox(const int8_t x, const int8_t y, Equipment* equipment)
    : GameObject(x, y), mEquipment(equipment) {}

    char EquipmentBox::GetSymbol() const {
        return 'B';
    }

    bool EquipmentBox::IsCharacter() const {
        return false;
    }

    bool EquipmentBox::IsEquipmentBox() const {
        return true;
    }

    bool EquipmentBox::IsWall() const {
        return false;
    }

    bool EquipmentBox::IsSpikeTrap() const {
        return false;
    }

    Equipment* EquipmentBox::GetEquipment() {
        Equipment* equipment = mEquipment;
        mEquipment = nullptr;
        return equipment;
    }
}
namespace rpg_extreme {
    SpikeTrap::SpikeTrap(const int8_t x, const int8_t y)
    : GameObject(x, y) {}

    char SpikeTrap::GetSymbol() const {
        return '^';
    }

    bool SpikeTrap::IsCharacter() const {
        return false;
    }

    bool SpikeTrap::IsEquipmentBox() const {
        return false;
    }

    bool SpikeTrap::IsWall() const {
        return false;
    }

    bool SpikeTrap::IsSpikeTrap() const {
        return true;
    }

    bool SpikeTrap::IsAttackable() const {
        return true;
    }

    void SpikeTrap::AttackTo(Character* const character) {
        Player* player = static_cast<Player*>(character);
        player->OnAttacked(this, 5);
    }
}
namespace rpg_extreme{
    Wall::Wall(const int8_t x, const int8_t y)
    : GameObject(x, y) {}

    char Wall::GetSymbol() const {
        return '#';
    }

    bool Wall::IsCharacter() const {
        return false;
    }

    bool Wall::IsEquipmentBox() const {
        return false;
    }

    bool Wall::IsWall() const {
        return true;
    }

    bool Wall::IsSpikeTrap() const {
        return false;
    }
}
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
                    // objVector.push_back(new GameObject(x, y));
                    break;
                case eSymbolType::WALL:
                    objVector.push_back(new Wall(x, y));
                    break;
                case eSymbolType::ITEM_BOX:
                    mItemBoxCount++;
                    break;
                case eSymbolType::SPIKE_TRAP:
                    objVector.push_back(new SpikeTrap(x, y));
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
                    mPlayer = new Player(x, y);
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
            {
                BossMonster* bossMonster = static_cast<BossMonster*>(gameObject);
                if (bossMonster) {
                    bossMonster->FillUpHp();
                    mGameObjects[bossMonster->GetY()][bossMonster->GetX()].push_back(bossMonster);
                }
                break;
            }
            case eSymbolType::MONSTER:
            {
                Monster* monster = static_cast<Monster*>(gameObject);
                if (monster) {
                    monster->FillUpHp();
                    mGameObjects[monster->GetY()][monster->GetX()].push_back(monster);
                }
                break;
            }
            case eSymbolType::PLAYER:
                Player* player = static_cast<Player *>(gameObject);
                if(player) {
                    //player->FillUpHp();
                    mGameObjects[player->GetY()][player->GetX()].push_back(player);
                }
                break;
            }
        }
        else if (gameObject->GetSymbol() == eSymbolType::ITEM_BOX) { // Character가 아닌 case
            EquipmentBox *equipmentBox = static_cast<EquipmentBox *>(gameObject);
            if (equipmentBox)
                mGameObjects[equipmentBox->GetY()][equipmentBox->GetX()].push_back(equipmentBox);
        }
        
    }

    bool Map::Remove(GameObject* const gameObject) {
        auto& objects = mGameObjects[gameObject->GetY()][gameObject->GetX()];
        for (auto itr = objects.begin(); itr != objects.end(); itr++)
        {
            if(gameObject == *itr){
                objects.erase(itr);
                return true;
            }
        }
        return false;
    }

    size_t Map::GetGameObjectCount(const int8_t x, const int8_t y) const {
        return mGameObjects[y][x].size();
    }

    GameObject* Map::GetGameObject(const int8_t x, const int8_t y, const uint8_t index) const{
        return mGameObjects[y][x][index];
    }

    bool Map::IsPassable(const int8_t x, const int8_t y) const {
        if(x >= mWidth || x < 0 || y >= mHeight || y < 0) return false;
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
                if(mPlayer->GetX() == x && mPlayer->GetY() == y && mPlayer->IsAlive())
                    ss << '@';
                else if(mGameObjects[y][x].empty())
                    ss << '.';
                else
                    ss << mGameObjects[y][x][0]->GetSymbol();
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
} namespace rpg_extreme{
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
            if(y == mMap->GetBossMonsterPosY() && x == mMap->GetBossMonsterPosX())
                mMap->Spawn(new BossMonster(x, y, name, attack, defense, maxHp, exp));
            else
                mMap->Spawn(new Monster(x, y, name, attack, defense, maxHp, exp));
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
                mMap->Spawn(new EquipmentBox(x, y, new Weapon(attack)));
                break;
            case eSymbolType::ARMOR:
                int defense;
                std::cin >> defense;
                mMap->Spawn(new EquipmentBox(x, y, new Armor(defense)));
                break;
            case eSymbolType::ACCESSORY:
            {
                char type[3];
                std::cin >> type;
                Accessory* accessory = (Accessory*)nullptr;
                if (!strcmp(type, "HR"))
                    accessory = new Accessory(eAccessoryEffectType::HP_REGENERATION);
                else if (!strcmp(type, "RE"))
                    accessory = new Accessory(eAccessoryEffectType::REINCARNATION);
                else if (!strcmp(type, "CO")) {
                    accessory = new Accessory(eAccessoryEffectType::COURAGE);
                    // mMap->GetPlayer()->SetCourageBuff();
                }
                else if (!strcmp(type, "EX"))
                    accessory = new Accessory(eAccessoryEffectType::EXPERIENCE);
                else if (!strcmp(type, "DX"))
                    accessory = new Accessory(eAccessoryEffectType::DEXTERITY);
                else if (!strcmp(type, "HU")) {
                    accessory = new Accessory(eAccessoryEffectType::HUNTER);
                    // mMap->GetPlayer()->SetHunterBuff();
                }
                else if (!strcmp(type, "CU"))
                    accessory = new Accessory(eAccessoryEffectType::CURSED);
                mMap->Spawn(new EquipmentBox(x, y, accessory));
                break;
            }
            default:
                assert(false);
            }
        }

        Player* player = mMap->GetPlayer();

        size_t moveCommandSize = moveCommand.length();
        for(mTurnCount = 0; mTurnCount < moveCommandSize; ++mTurnCount) {
            char d = moveCommand[mTurnCount];
            switch (d) {
            case 'L':
                player->MoveLeft();
                break;
            case 'R':
                player->MoveRight();
                break;
            case 'U':
                player->MoveUp();
                break;
            case 'D':
                player->MoveDown();
                break;
            default:
                assert(false);
            }
            int x = player->GetX(), y = player->GetY();
            int cnt = mMap->GetGameObjectCount(x, y);
            if (cnt >= 2)
            {
                GameObject *gameObject = mMap->GetGameObject(x, y, 0);
                switch(gameObject->GetSymbol()) {
                case eSymbolType::MONSTER:
                    battleWithMonster(static_cast<Monster*>(gameObject));
                    break;
                case eSymbolType::BOSS_MONSTER:
                    battleWithBossMonster(static_cast<BossMonster*>(gameObject));
                    if (mPlayerKillerName != "" || mbGameClear) return;
                    break;
                case eSymbolType::SPIKE_TRAP:
                    stepOnSpikeTrap(static_cast<SpikeTrap*>(gameObject));
                    break;
                case eSymbolType::ITEM_BOX:
                    openEquipmentBox(static_cast<EquipmentBox*>(gameObject));
                    break;
                }
                if (!player->IsAlive()) return;
            }
        }
        mTurnCount--;
    }

    void Game::Shutdown() {
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
        //TODO: HUNTER 장신구 효과 활성화
        bool isHunter = player->HasAccessoryEffect(eAccessoryEffectType::HUNTER);
        bool isCourage = player->HasAccessoryEffect(eAccessoryEffectType::COURAGE);
        bool isDex = player->HasAccessoryEffect(eAccessoryEffectType::DEXTERITY);
        while(player->IsAlive() && bossMonster->IsAlive()) {
            if(isCourage) {
                //TODO: COURAGE 처리
                player->SetCourageBuff();
                if (isHunter) player->FillUpHp();
                if (isDex) {
                    player->SetHunterBuff();
                    player->AttackTo(bossMonster);
                    
                    player->SetHunterBuff();
                }
                else 
                    player->AttackTo(bossMonster);

                isCourage = false;
                player->SetCourageBuff();
                if (!bossMonster->IsAlive()) break;
                if (!isHunter) player->OnAttacked(bossMonster, bossMonster->GetAttack());
                if (!player->IsAlive()) break;
            }
            player->AttackTo(bossMonster);
            if (!(bossMonster->IsAlive()))
                break;
            player->OnAttacked(bossMonster, bossMonster->GetAttack());
        }
        if(player->IsAlive()) {
            if(player->HasAccessoryEffect(eAccessoryEffectType::EXPERIENCE))
                player->AddExp((int)(bossMonster->GetExp() * 1.2));
            else
                player->AddExp(bossMonster->GetExp());
            
            if(player->HasAccessoryEffect(eAccessoryEffectType::HP_REGENERATION))
                player->AddHp(3);
            mMap->Remove(bossMonster);
            mbGameClear = true;
        }
        else {
            if(player->HasAccessoryEffect(eAccessoryEffectType::REINCARNATION)) {
                player->MoveTo(player->GetInitX(), player->GetInitY());
                player->FillUpHp();
                player->UnequipReincarnationAccessory();
                bossMonster->FillUpHp();
                
            }
            else {
                mPlayerKillerName = bossMonster->GetName();
                //mMap->Remove(player);
            } 
        }
        //Game::GetInstance().Shudown();
    }

    void Game::battleWithMonster(Monster* const monster) {
        Player *player = mMap->GetPlayer();
        if(monster->IsBoss())
            battleWithBossMonster(static_cast<BossMonster*>(monster));
        else {
            bool isCourage = player->HasAccessoryEffect(eAccessoryEffectType::COURAGE);
            bool isDex = player->HasAccessoryEffect(eAccessoryEffectType::DEXTERITY);
            while(player->IsAlive() && monster->IsAlive()) {
                if(isCourage) {
                    player->SetCourageBuff();
                    if (isDex) {
                        player->SetHunterBuff();
                        player->AttackTo(monster);
                        player->SetHunterBuff();
                    }
                    else
                        player->AttackTo(monster);
                    
                    isCourage = false;
                    player->SetCourageBuff();
                    if (!monster->IsAlive()) break;
                    player->OnAttacked(monster, monster->GetAttack());
                    if(!player->IsAlive()) break;

                }
                player->AttackTo(monster);
                if (!(monster->IsAlive()))
                    break;
                player->OnAttacked(monster, monster->GetAttack());
            }
        }
        if(player->IsAlive()) {
            //TODO: HP Regeneration, Experience 장신구 효과 활성화
            if (player->HasAccessoryEffect(eAccessoryEffectType::EXPERIENCE))
                player->AddExp((int)(monster->GetExp() * 1.2));
            else
                player->AddExp(monster->GetExp());

            if (player->HasAccessoryEffect(eAccessoryEffectType::HP_REGENERATION))
                player->AddHp(3);
            mMap->Remove(monster);
        }
        else {
            //TODO: Reincarnation 장신구 효과 활성화
            if (player->HasAccessoryEffect(eAccessoryEffectType::REINCARNATION)) {
                player->MoveTo(player->GetInitX(), player->GetInitY());
                player->UnequipReincarnationAccessory();
                player->FillUpHp();
                monster->FillUpHp();
            }
            else {
                //mMap->Remove(player);
                //Game::GetInstance().Shudown();
                mPlayerKillerName = monster->GetName();
            }
        }
    }

    void Game::openEquipmentBox(EquipmentBox* const equipmentBox) {
        Player* player = mMap->GetPlayer(); 
        Equipment* equipment = equipmentBox->GetEquipment();
        if(equipment->IsWeapon()) {
            Weapon* weapon = static_cast<Weapon*>(equipment);
            player->EquipWeapon(weapon);
        }
        else if(equipment->IsArmor()) {
            Armor* armor = static_cast<Armor*>(equipment);
            player->EquipArmor(armor);
        }
        else if(equipment->IsAccessory()) {
            Accessory* accessory = static_cast<Accessory*>(equipment);
            player->EquipAccessory(accessory);
        }
        else
            assert(false);
        mMap->Remove(equipmentBox);
    }

    void Game::stepOnSpikeTrap(SpikeTrap* const spikeTrap) {
        Player *player = mMap->GetPlayer();
        //TODO: Dexterity 장신구 효과 활성화
        if(player->HasAccessoryEffect(eAccessoryEffectType::DEXTERITY))
            player->OnAttacked(spikeTrap, 1);
        else
            player->OnAttacked(spikeTrap, 5);
        if (!player->IsAlive()) {
            if (player->HasAccessoryEffect(eAccessoryEffectType::REINCARNATION)) {
                player->MoveTo(player->GetInitX(), player->GetInitY());
                player->UnequipReincarnationAccessory();
                player->FillUpHp();
            }
            else 
                mPlayerKillerName = "SPIKE TRAP";
        }
            
    }

    std::string Game::GetResultToString() const {
        std::stringstream ss;

        Player *player = mMap->GetPlayer();
        int16_t hp = player->GetHp();
        if(hp < 0) hp = 0;
        ss << mMap->ToString();
        ss << "Passed Turns : " << mTurnCount + 1 << '\n';
        ss << "LV : " << player->GetLevel() << '\n';
        ss << "HP : " << hp << '/' << player->GetMaxHp() << '\n';
        ss << "ATT : " << player->GetAttack() << '+' << player->GetWeaponAttack() << '\n';
        ss << "DEF : " << player->GetDefense() << '+' << player->GetArmorDefense() << '\n';
        ss << "EXP : " << player->GetExp() << '/' << player->GetMaxExp() << '\n';

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

using namespace rpg_extreme;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Game& game = Game::GetInstance();
    game.Start();

    std::cout << game.GetResultToString();

    game.Shutdown();

    return 0;
}
