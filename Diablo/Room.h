#pragma once
#include <vector>
#include "Chest.h"
#include "Enemy.h"
#include "ItemFactory.h"

#include "Player.h"
#include "Spell.h"


class Room
{

public:
    Room(const char* aName, int aDoorsAmount, int aEnemies, bool aHasCest, bool aHasItem, Spell& aSpell);
    // Room(const char* aName, const int aDoorsAmount, const int aEnemies, bool aHasCest, bool aHasItem,  Spell& aSpell)
    //     : myItemFactory(), mySpell(aSpell)
    //
    // {
    //     PopulateItems();
    //     myName = aName;
    //     myDoorsAmount = aDoorsAmount;
    //     myEnemies = aEnemies;
    //     myHasChest = aHasCest;
    //     if (myEnemies > 0)
    //     {
    //         myHasEnemies = true;
    //     }
    //     myHasItems = aHasItem;
    //     myHasSpell = true;
    // }


    const char* GetName() const { return myName; }
    int GetDoorAmount() const { return myDoorsAmount; }
    int GetEnemiesAmount() const { return myEnemies; }
   
    void PrintRoomData(const std::vector<Enemy>* aPopulatiion) const;
    void PrintEnterRoom(const Player& aPlayer) const;
    void SetDoors(const int aDoors) { myDoorsAmount = aDoors; }
    bool GetHasChest() const { return myHasChest; }
    bool GetHasItems() const { return myHasItems; }
    bool GetHasSpell() const { return myHasSpell; }
    void SetHasSpell(const bool aActive) { myHasSpell = aActive; }
    void SetHasChest(bool aHasChest) { myHasChest = aHasChest; }
    void SetHasItems(bool aHasItems) { myHasItems = aHasItems; }

    void PopulateItems();
    Item&GetItem() { return *myCurrentItem ;}
    Spell& GetSpell() { return mySpell; }

private:
    
   ItemFactory myItemFactory;
   Item myItem0 = myItemFactory.CreateItem(enumItemType::Hammer);
   Item myItem1 = myItemFactory.CreateItem(enumItemType::Sword);
   Item  myItem2 = myItemFactory.CreateItem(enumItemType::Horn);
    std::vector<Item> myItems;
    Item* myCurrentItem = &myItems[0];
    Spell mySpell;
    int myDoorsAmount = 2;
    int myEnemies{};
    const char* myName = "Room";
    bool myHasChest = false;
    bool myHasItems = false;
    bool myHasSpell = false;
    bool myHasEnemies = false;
};
