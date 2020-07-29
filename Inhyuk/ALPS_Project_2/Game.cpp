#include "Game.h"
 
namespace rpg_extreme
{
    Game* Game::sInstance = nullptr;
 
    Game& Game::GetInstance()
    {
        if (sInstance == nullptr)
        {
            sInstance = new Game();
        }
        return *sInstance;
    }
 
    void Game::Start()
    {
        // Input Map data
        int width;
        int height;
        std::vector<std::string> mapData;
 
        std::cin >> height >> width;
        mapData.reserve(height);
 
        for (int i = 0; i < height; ++i)
        {
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
        for (size_t i = 0; i < monsterCount; ++i)
        {
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
            mMap->Spawn(new Monster(x, y, name, attack, defense, maxHp, exp));
        }
 
        // Input equipment data
        size_t itemBoxCount = mMap->GetItemBoxCount();
        for (size_t i = 0; i < itemBoxCount; ++i)
        {
            int y;
            int x;
            char equipmentSymbolType;
 
            std::cin >> y >> x >> equipmentSymbolType;
 
            --y;
            --x;

            Equipment* equip = nullptr;
            switch (equipmentSymbolType)
            {
            case eSymbolType::WEAPON:
                int attack;
                std::cin >> attack;
                equip = new Weapon(attack);
                // mMap->Spawn(new EquipmentBox(x, y, new Weapon(attack)));
                break;
 
            case eSymbolType::ARMOR:
                int defense;
                std::cin >> defense;
                equip = new Armor(defense);
                break;
 
            case eSymbolType::ACCESSORY:
                char type[3];
                std::cin >> type;
                if(type[0] == 'H' && type[1] == 'R')
                    equip = new Accessory(eAccessoryEffectType::COURAGE);
                else if(type[0] == 'R' && type[1] == 'E')
                    equip = new Accessory(eAccessoryEffectType::REINCARNATION);
                else if(type[0] == 'C' && type[1] == 'O')
                    equip = new Accessory(eAccessoryEffectType::COURAGE);
                else if(type[0] == 'E' && type[1] == 'X')
                    equip = new Accessory(eAccessoryEffectType::EXPERIENCE);
                else if(type[0] == 'D' && type[1] == 'X')
                    equip = new Accessory(eAccessoryEffectType::DEXTERITY);
                else if(type[0] == 'H' && type[1] == 'U')
                    equip = new Accessory(eAccessoryEffectType::HUNTER);
                else
                    equip = new Accessory(eAccessoryEffectType::CURSED);
                break;
            default:
                assert(false);
            }
            mMap->Spawn(new EquipmentBox(x, y, equip));
        }
 
        Player* player = mMap->GetPlayer();
 
        size_t moveCommandSize = moveCommand.length();
        for (mTurnCount = 0; mTurnCount < moveCommandSize; ++mTurnCount)
        {
            char d = moveCommand[mTurnCount];
            switch (d)
            {
            case 'L':
                if(mMap->IsPassable(player->GetX()-1, player->GetY()))
                    player->MoveLeft();
                break;
 
            case 'R':
                if(mMap->IsPassable(player->GetX()+1, player->GetY()))
                    player->MoveRight();
                break;
 
            case 'U':
                if(mMap->IsPassable(player->GetX(), player->GetY()-1))
                    player->MoveUp();
                break;
 
            case 'D':
                if(mMap->IsPassable(player->GetX(), player->GetY()+1))
                    player->MoveDown();
                break;
 
            default:
                assert(false);
            }
            GameObject* object = mMap->GetGameObject(player->GetX(), player->GetY(), 0);
            char symbol = object->GetSymbol();
            
            if(symbol == eSymbolType::MONSTER)
                battleWithMonster(static_cast<Monster*>(object));

            else if(symbol == eSymbolType::BOSS_MONSTER)
                battleWithBossMonster(static_cast<BossMonster*>(object));

            else if(symbol == eSymbolType::SPIKE_TRAP)
                stepOnSpikeTrap(static_cast<SpikeTrap*>(object));

            else if(symbol == eSymbolType::ITEM_BOX)
                openEquipmentBox(static_cast<EquipmentBox*>(object));
            
        }     
    }
 
    void Game::Shutdown()
    {
        delete sInstance;
    }
 
    Map& Game::GetMap() const
    {
        return *mMap;
    }
 
    Game::Game()
        : mMap(nullptr)
        , mTurnCount(0)
        , mbGameClear(false)
    {
    }
 
    Game::~Game()
    {
        delete mMap;
    }
 
    void Game::battleWithBossMonster(BossMonster* const bossMonster)
    {
        Player* player = mMap->GetPlayer();
    }
 
    void Game::battleWithMonster(Monster* const monster)
    {
        Player* player = mMap->GetPlayer();
        while(true){
            if(monster->IsAttackedable() && player->IsAttackable())
                player->AttackTo(monster);
            if(monster->GetHp() <= 0) break;

            if(player->IsAttackedable() && monster->IsAttackable())
                monster->AttackTo(player);
            if(player->GetHp() <= 0) break;
        }
    }
 
    void Game::openEquipmentBox(EquipmentBox* const equipmentBox)
    {
        Player* player = mMap->GetPlayer();
        Equipment* equip = equipmentBox->GetEquipment();
        if(equip->IsWeapon())
            player->EquipWeapon(static_cast<Weapon*>(equip));
            
        else if(equip->IsArmor())
            player->EquipArmor(static_cast<Armor*>(equip));

        else if(equip->IsAccessory())
            player->EquipAccessory(static_cast<Accessory*>(equip));
        
    }
 
    void Game::stepOnSpikeTrap(SpikeTrap* const spikeTrap)
    {
        Player* player = mMap->GetPlayer();
        spikeTrap->AttackTo(player);
    }
 
    std::string Game::GetResultToString() const
    {
        std::stringstream ss;
 
        Player* player = mMap->GetPlayer();
 
        ss << mMap->ToString();
        ss << "Passed Turns : " << 0 << '\n';
        ss << "LV : " << player->GetLevel() << '\n';
        ss << "HP : " << player->GetHp() << '/' << player->GetMaxHp() << '\n';
        ss << "ATT : " << player->GetAttack() << '+' << 0 << '\n';
        ss << "DEF : " << player->GetDefense() << '+' << 0 << '\n';
        ss << "EXP : " << player->GetExp() << '/' << player->GetMaxExp() << '\n';
 
        if (mbGameClear)
        {
            ss << "YOU WIN!" << '\n';
        }
        else
        {
            if (player->IsAlive())
            {
                ss << "Press any key to continue." << '\n';
            }
            else
            {
                ss << "YOU HAVE BEEN KILLED BY " << mPlayerKillerName << ".." << '\n';
            }
        }
 
        ss << '\n';
 
        return ss.str();
    }
}