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

    int GetHealth() const { return myHealth; }
    int MaxHealth() const { return myMaxHealth; }
    int GetDamage() const { return myAtk; }
    bool GetIsAlive() const { return myIsAlive; }
    const char* GetName() const { return myName; }
    void TakeDamage(int aDamage);

private:
    char myName[17] = {};
    int myMaxHealth{};
    int myHealth{};
    int myAtk{};
    bool myIsAlive = true;
};
