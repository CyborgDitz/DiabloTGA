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

void Room::SetRoomState(GameManager& aGame)
{
        const int min = 0;
        //todo enum
        int choice = aGame.GetInput(min,sizeof(myMenu));
       myMenu= static_cast<myMenu>(choice);
}

void Room::RoomMenuStuff(GameManager& aGame)
{
    {
        std::cout << "I am in the main menu saying the dungoeon name" << std::endl;
        
        {
            std::cout << "thes are the choices" << std::endl;
            std::cout << "1: Explore\t 2: Attack the Monsters!\t 3: See your stats\t 4: Open Door "  << std::endl;
            SetRoomState(aGame);
        }

        if (myMenu == RoomMenu::Exit)
        {
            std::cout << "I am the ending the game cuz im dead i guess" << std::endl;
        }
        else if (myMenu == RoomMenu::Explore)
        {
            std::cout << "I am in the room menu saying whats inside it" << std::endl;
        }
        else if (myMenu == RoomMenu::Combat)
        {
            std::cout << "pow pow pow" << std::endl;
        }
    }
}
