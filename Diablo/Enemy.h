#pragma once
#include <string>

class Enemy
{
public:
    Enemy(const int aMaxHealth, int aMyAtk, const char* aName)
    {
        myMaxHealth = aMaxHealth;
        myHealth = myMaxHealth;
        myAtk = aMyAtk;
        strcpy_s(myName, aName);
    }

    int GetHealth() { return myHealth; }
    int MaxHealth() { return myMaxHealth; }
    int GetDamage() { return myAtk; }
    bool GetAlive() { return myIsAlive; }
    const char* GetName() const { return myName; }
    bool GetIsAlive() { return myIsAlive; }
    void TakeDamage(int aDamage);

private:
    char myName[17] = {};
    int myMaxHealth{};
    int myHealth{};
    int myAtk{};
    const int myDieAtThisNumber = 0;
    bool myIsAlive = true;
};
