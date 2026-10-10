#pragma once
#include <vector>

#include "Chest.h"
#include "Enemy.h"
#include "Library.h"
#include "Player.h"
#include "Spell.h"


class Room
{
public:
    Room(const char* aName, const int aDoorsAmount, const int aEnemies, bool aHasCest, bool aHasItem, Item& aItem, Spell& aSpell)
        : myItem(aItem), mySpell(aSpell)
    {
        myName = aName;
        myDoorsAmount = aDoorsAmount;
        myEnemies = aEnemies;
        myHasChest = aHasCest;
        if (myEnemies > 0)
        {
            myHasEnemies = true;
        }
        myHasItems = aHasItem;
        myHasSpell = true;
    }


    const char* GetName() const { return myName; }
    int GetDoorAmount() const { return myDoorsAmount; }
    int GetEnemiesAmount() const { return myEnemies; }
    void PrintRoomData(std::vector<Enemy>* aPopulatiion);
    void PrintEnterRoom(const Player& aPlayer) const;
    void SetDoors(const int aDoors) { myDoorsAmount = aDoors; }
    bool GetHasChest() const { return myHasChest; }
    bool GetHasItems() const { return myHasItems; }
    bool GetHasSpell() const { return myHasSpell; }
    void SetHasSpell(const bool aActive) { myHasSpell = aActive; }
    void SetHasChest(bool aHasChest) { myHasChest = aHasChest; }
    void SetHasItems(bool aHasItems) { myHasItems = aHasItems; }
    
    Item& GetItem() { return myItem; }
    Spell& GetSpell() { return mySpell; }

private:
    Item myItem;
    Spell mySpell;
    int myDoorsAmount = 2;
    int myEnemies{};
    const char* myName = "Room";
    bool myHasChest = false;
    bool myHasItems = false;
    bool myHasSpell = false;
    bool myHasEnemies = false;
};
