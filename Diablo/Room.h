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
    Room(const char* aName, const int aDoorsAmount, const int aEnemies, bool aHasItem, Chest& aChest, Item& aItem)
        : myChest(aChest), myItem(aItem)
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
    Chest& GetChest() { return myChest; }

    void CastSpell();
    Spell::Element& GetElement() { return myElement; }
    //void SetState();

    Spell mySpell0 {"BoomBadaboom", 3,3, true, 3, Spell::Fire};
    Spell mySpell1 {"BoomBadaboom", 1,2, true, 3, Spell::Ice};
    Spell mySpell2  {"BoomBadaboom", 9999,9999, true, 3, Spell::Blob};
private:
    Item myItem;
    Chest myChest;
    Spell::Element myElement = Spell::Element::None;
    int myDoorsAmount = 2;
    int myEnemies{};
    const char* myName = "Room";
    bool isSpellActive = false;
    bool myHasItems;
    bool myHasEnemies = false;
};
