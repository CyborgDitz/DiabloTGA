#include "Room.h"
#include <iostream>

#include "GameManager.h"

void Room::PrintStats() const
{
    std::cout << "The room id: " << myRoomID<< std::endl;
    std::cout << "The  amount of doors " << myDoors << std::endl;
    std::cout << "The amount of Enemies " << myEnemies << std::endl;
    std::cout << "If I had loot I would say it here :( " << std::endl;
}


