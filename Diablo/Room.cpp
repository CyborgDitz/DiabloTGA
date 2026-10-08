#include "Room.h"
#include <iostream>

#include "GameManager.h"
#include "Library.h"

void Room::PrintRoomData() const
{
    std::cout << "Room: "<< myName << " has " << myDoorsAmount << " doors! " << std::endl;
    if (myHasEnemies == true)
    {
        std::cout << "There are Enemies!! Watch out! " << std::endl;
    }
    else
    {
        std::cout << myEnemies << " The room has no monsters! " << std::endl;
    }

    std::cout << "If I had loot I would say it here :( \n" << std::endl;
    std::cout << "If I had spell elements I would say it here :( \n" << std::endl;
}

void Room::PrintEnterRoom(const Player& aPlayer) const
{
        system("cls");
        std::cout << aPlayer.GetName() << '\t' <<
            " enters the... " << '\t' <<
            myName << '\n' << std::endl;
}

