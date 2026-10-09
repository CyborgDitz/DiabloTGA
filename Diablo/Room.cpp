#include "Room.h"
#include <iostream>
#include "GameManager.h"

void Room::PrintRoomData(std::vector<Enemy>* aPopulatiion)
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
   // std::cout << "My spell is " << mySpell << std::endl;
}

void Room::CastSpell(Spell& aSpell)
{
    int theMainMod = aSpell.GetMainMod();
    int theSecondMod = aSpell.GetSecondMod();
    bool isConsumed = aSpell.GetIsConsumed();
    int theTimer = aSpell.GetTimer();
    std::cout << "I am charged with "  << std::endl;
    switch (myElement)
    {
    case Spell::Element::None:
        {
            std::cout << "NUTHIN" << std::endl;
            break;
        }
    case Spell::Element::Fire:
        {
            std::cout << "Fire!!!" << std::endl;
            break;
        }
    case Spell::Element::Ice:
        {
            std::cout << "Ice!!!" << std::endl;
            break;
        }
    case Spell::Element::Blob:
        {
            std::cout << "... wait what. Wtf is this slime? It looks delicious" << std::endl;
            break;
        }
    case Spell::Element::Count:
        {
            break;
        }
    default: 
        ;
    }
    std::cout << "Stat Buffs: Main = " <<theMainMod << "and Secondary stat: "<< theSecondMod<< std::endl;
    
    if (isConsumed == true)
    {
        std::cout << "\n  only one turn!" <<std::endl;
    }
    else
    {
        std::cout << "\n and lasts for " << theTimer<<" turns!" <<std::endl;
    }
  SetHasSpell(false);
}

void Room::PrintEnterRoom(const Player& aPlayer) const
{
        system("cls");
        std::cout << aPlayer.GetName() << '\t' <<
            " enters the... " << '\t' <<
            myName << '\n' << std::endl;
}


