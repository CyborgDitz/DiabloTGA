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
    Room(const char* aName, const int aDoorsAmount, const int aEnemies, bool aHasItem, Item& aItem)
        : myItem(aItem)
    {
        myName = aName;
        myDoorsAmount = aDoorsAmount;
        myEnemies = aEnemies;
        if (myEnemies > 0)
        {
            myHasEnemies = true;
        }
        myHasItems = aHasItem;
    }


    const char* GetName() const { return myName; }
    int GetDoorAmount() const { return myDoorsAmount; }
    int GetEnemiesAmount() const { return myEnemies; }
    void PrintRoomData(std::vector<Enemy>* aPopulatiion);
    void PrintEnterRoom(const Player& aPlayer) const;
    void SetDoors(const int aDoors) { myDoorsAmount = aDoors; }
    bool HasItems() const { return myHasItems; }
    bool GetSpell() const { return myHasItems; }

    void SetSpellActive(const bool aActive) { myHasItems = aActive; }


    Item& GetItem() { return myItem; }
    //hest& GetChest() { return myChest; }

    void CastSpell(Spell& aSpell);
    Spell::Element& GetElement() { return myElement; }
    //void SetState();

    
private:
    Item myItem;
   // Chest myChest;
    Spell::Element myElement = Spell::Element::None;
    int myDoorsAmount = 2;
    int myEnemies{};
    const char* myName = "Room";
    bool isSpellActive = false;
    bool myHasItems;
    bool myHasEnemies = false;
};
