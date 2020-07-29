#pragma once
 
#include <string>
 
#include "Character.h"
#include "Player.h"
#include "eSymbolType.h"
#include "IAttackable.h"
#include "IAttackedable.h"
 
namespace rpg_extreme
{
    class Monster : public Character, public IAttackable, public IAttackedable
    {
    public:
        Monster(const int8_t x, const int8_t y, const std::string& name, const int16_t attack, const int16_t defense, const int16_t hp, const uint16_t exp);
        
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
