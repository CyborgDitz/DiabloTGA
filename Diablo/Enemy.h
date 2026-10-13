#pragma once
#include <string>

#include "EnemyType.h"
enum class enumEnemyType
{
    Blob,
    BigBlob,
    Diablob,
    Count
};
class Enemy
{

    public:
  
    Enemy(const EnemyType& aEnemyType);
    int GetHealth()const {return myEnemyType->GetMaxHealth();}
    int GetMaxHealth() const { return myMaxHealth; }
    int GetAtk() const{ return myEnemyType->GetAtk();}
    int GetDef() const {return myEnemyType->GetDefense(); }
    const char* GetName() const {return myEnemyType->GetName(); }
    
    bool GetIsAlive() const { return myIsAlive; }
    void SetIsAlive(bool aIsAlive) { myIsAlive = aIsAlive; }
    
    void TakeDamage(int aDamage);
    void PrintStats() const;
    
    private:
    int myHealth;
    int myMaxHealth;
    int myAtk;
    int myDefense;
    int myIsAlive = true;
        const EnemyType* myEnemyType;
};
