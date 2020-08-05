#include "Game.h"
#include <cstring>
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
        if (hp < 0) hp = 0;
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