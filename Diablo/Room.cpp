#include "Room.h"
#include <iostream>



Room::Room(const char* aName, const int aDoorsAmount, const int aEnemies, bool aHasCest, bool aHasItem, Item& aItem,
    Spell& aSpell) : myItem(aItem), mySpell(aSpell)
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

void Room::PrintRoomData(const std::vector<Enemy>* aPopulatiion) const
{
    std::cout << "Room: "<< myName << " has " << myDoorsAmount << " doors! " << std::endl;
    if (aPopulatiion->size() > 0)
    {
        std::cout << "There are: " << aPopulatiion->size()<< " enemies in here!"<< std::endl;
    }
    else
    {
        std::cout << "No enemies present!" << std::endl;
    }
    if (myHasChest == true)
    {
        std::cout << "There is a chest! I will open it right now!" << std::endl;
    }
    if (myHasItems == true)
    {
        std::cout << "The loot is: " << myItem.GetName() << std::endl;
    }
    std::cout << "Your spellbook finds a powerful magic in the room! But yo ucan only use it once! It is " << mySpell.GetName()<< std::endl;
   // std::cout << "My spell is " << mySpell << std::endl;
}

void Room::PrintEnterRoom(const Player& aPlayer) const
{
        system("cls");
        std::cout << aPlayer.GetName() << '\t' <<
            " enters the... " << '\t' <<
            myName << '\n' << std::endl;
}