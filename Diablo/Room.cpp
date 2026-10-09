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



void Room::PrintEnterRoom(const Player& aPlayer) const
{
        system("cls");
        std::cout << aPlayer.GetName() << '\t' <<
            " enters the... " << '\t' <<
            myName << '\n' << std::endl;
}


