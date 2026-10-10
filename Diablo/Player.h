#pragma once
#include <vector>
#include "Item.h"
#include "Spell.h"

class Player
{
public:
    Player(const int aMyStr, const int aMyVit, const int aMyDex)
    {
        myStr = aMyStr;
        myDex = aMyDex;
        myVit = aMyVit;
        myAtk = (myStr * myDex);
        myMaxHealth = (myVit * 4) + (myStr * 6) + (myDex * 3);
        myHealth = myMaxHealth;
        myCarryCap = myStr + (myDex * 3);
        myDefense = myVit + (myDex);
    }

    int GetAtk() const { return myAtk; }
    int GetStr() const { return myStr; }
    int GetDex() const { return myDex; }
    int GetVit() const { return myVit; }
    int GetHealth() const { return myHealth; }
    int GetIsAlive() const { return myAtk; }
    int GetMaxHealth() const { return myMaxHealth; }
    int GetDefense() const { return myDefense; }
    int GetCarryCap() const { return myCarryCap; }
    const char* GetName() const { return myName; }
  
    void SetStr(const int aStr) { myStr = aStr; }
    void SetDex(const int aDex) { myDex = aDex; }
    void SetVit(const int aVit) { myVit = aVit; }
    void SetHealth(const int aHealth) { myHealth = aHealth; }
    void SetMaxHealth(const int aMaxHealth) { myMaxHealth = aMaxHealth; }
    void SetDefense(const int aDefense) { myDefense = aDefense; }
    void SetCarryCap(const int aCap) { myCarryCap = aCap; }

    int CalcPlayerAttack() const;

    void TakeDamage(int aDamage);
    bool GetIsAlive() { return myIsAlive; }

    bool GetInfinite() const { return hasInfinite; }
    bool GetGodMode() const { return hasGodMode; }
    void SetInfinite(bool aBool) { hasInfinite = aBool; }
    void SetGodMode(bool aBool) { hasGodMode = aBool; }


    void PrintStats() const;

    void PopulateInventory(Item& aItem);
    void RemoveFromInventory(Item& aItem);
    void PopulateSpells(Spell& aSpell);
    void RemoveFromSpells(Spell& aSpell);
    void CastSpell();
    void RemoveSpell();

    // PopulateSpells(mySpells);

    std::vector<Item> GetInventory() const { return myInventory; }

 

private:
    //  const char* myName[17] = {}; not MVP
    char myName[17] = "Bob";
    int myStr{};
    int myDex{};
    int myVit{};
    int myHealth{};
    int myAtk{};
    int myMaxHealth{};
    int myCarryCap{};
    int myDefense{};

    bool hasSpellActive = false;
    bool myIsAlive = true;
    bool hasGodMode = false;
    bool hasInfinite = false;
    std::vector<Item> myInventory;
    std::vector<Spell> mySpellBook;
};
