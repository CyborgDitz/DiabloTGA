#pragma once
#include <string>

class Enemy
{
public:
    
    Enemy (int aMaxHealth, int amyAtk, const char* aName)
    {
        int myMaxHealth = aMaxHealth;
        int myAtk = amyAtk;
        std::strcpy(myName, aName);
    }
    int GetHealth(){return myHealth;}
    int MaxHealth(){return myMaxHealth;}
    int GetDamage(){return myAtk;}
    bool GetAlive(){return myIsAlive;}
    const char* GetName() const { return myName; }
    
    void TakeDamage(int aDamage){myHealth -= aDamage;}
    int DealDamage(){return myAtk;}
 
private:
    int myHealth{};
    int myMaxHealth{};
    int myAtk{};
    bool myIsAlive = true;
    const int myDieAtThisNumber= 0;
    char myName[17] = {};
};
