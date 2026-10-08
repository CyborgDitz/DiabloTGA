#include "Room.h"
#include <iostream>

#include "GameManager.h"
#include "Library.h"

void Room::PrintRoomData(std::vector<Enemy>* aPopulatiion) const
{
    std::cout << "Room: "<< myName << " has " << myDoorsAmount << " doors! " << std::endl;
    std::cout << "There are: " << aPopulatiion->size()<< " enemies in here!"<< std::endl;
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

