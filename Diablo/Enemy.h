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
    
  //  int GetHealth() const {return myHealth;}
    void SetHealth(const int aHealth){ myHealth = aHealth;}
    bool GetIsAlive() const { return myIsAlive; }
    void SetIsAlive(const bool aIsAlive) { myIsAlive = aIsAlive; }
    
    int GetMaxHealth() const;
    int GetHealth() const;
    int GetAtk() const;
    int GetDef() const ;
    const char* GetName() const;
    
    void TakeDamage(int aDamage);
    void PrintStats() const;
    
    private:
    int myMaxHealth{};
   int myHealth{};
    // int myDefense;
   int myIsAlive = true;
        const EnemyType* myEnemyType;
};
