#pragma once

class Enemy
{
public:
    
    Enemy (int aMaxHealth, int aMyDamage)
    {
        int myMaxHealth = aMaxHealth;
        int myDamage = aMyDamage;
    }
    int GetHealth(){return myHealth;}
    int MaxHealth(){return myMaxHealth;}
    int GetDamage(){return myDamage;}
    bool GetAlive(){return myIsAlive;}
private:
    int myHealth{};
    int myMaxHealth{};
    int myDamage{};
    bool myIsAlive = true;
    const int myDieAtThisNumber= 0;
};
