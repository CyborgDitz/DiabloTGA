#pragma once
#include <string>

class Enemy
{
public:
    Enemy( const char* aName, const int aMaxHealth, const int aMyAtk)
    {
        strcpy_s(myName, aName);
        myMaxHealth = aMaxHealth;
        myHealth = myMaxHealth;
        myAtk = aMyAtk;
    }

    int GetHealth() const { return myHealth; }
    int MaxHealth() const { return myMaxHealth; }
    int GetAtk() const { return myAtk; }
    bool GetIsAlive() const { return myIsAlive; }
    int GetDefense() const { return myDefense; }
    const char* GetName() const { return myName; }
    void TakeDamage(int aDamage);
    void PrintStats() const;

private:
    char myName[17] = {};
    int myMaxHealth{};
    int myHealth{};
    int myAtk{};
    int myDefense{};
    bool myIsAlive = true;
};
