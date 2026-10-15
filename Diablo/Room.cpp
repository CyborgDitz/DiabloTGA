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
    myHasSpell = aSpell.GetHasSpellSlot();
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
        std::cout << "There is a chest!! " << std::endl;
    }
    if (myHasItems == true)
    {
        std::cout << "The loot is: " << myItem.GetName() << std::endl;
    }
    if (myHasSpell == true)
    {

        std::cout << "Your spellbook finds a powerful magic in the room! But you can only use it once!\n "
                     "It is " << mySpell.GetName()<< std::endl;
    }
    else
    {
        std::cout << "There is no longer any magic here..." << std::endl;
    }
   // std::cout << "My spell is " << mySpell << std::endl;
}

void Room::PrintEnterRoom(const Player& aPlayer) const
{
        ("cls");
        std::cout << aPlayer.GetName() << '\t' <<
            " enters the... " << '\t' <<
            myName << '\n' << std::endl;
}