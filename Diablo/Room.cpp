#include "Room.h"
#include <iostream>
#include "Library.h"

void Room::ExploreRoom() const
{
    std::cout << "Room: "<< myName << " has " << myDoorsAmount << " doors! " << std::endl;
    if (myHasEnemies == true)
    {
        std::cout << "There are " << myEnemies << " Enemies!! Watch out! " << std::endl;
    }
    else
    {
        std::cout << myEnemies << " The room has no monsters! " << std::endl;
    }

    std::cout << "If I had loot I would say it here :( \n" << std::endl;
}

void Room::PrintEnterRoom(const Player& aPlayer) const
{
        system("cls");
        std::cout << aPlayer.GetName() << '\t' <<
            " enters the... " << '\t' <<
            myName << '\n' << std::endl;
}
void Room::RoomMenuChoices(const Player& aPlayer) const
{
    std::cout << "1: Open Door \t 2: Fight Monsters!\t 3:Explore Room\n" <<
                 " 4: See yours and monsters stats\t 0: Exit the game" << std::endl;

    RoomState input = static_cast<RoomState>(Library::SetInput(0, myStateLength));
    const RoomState state = (input);
    //call from room like print etc
    if (state == RoomState::Exit)
    {
        std::cout << "I am the ending the game cuz Im dead I guess" << std::endl;
    }
    else if (state == RoomState::Explore)
    {
        ExploreRoom();
       
    }
    else if (state == RoomState::Combat)
    {
        std::cout << "I am fighting" << std::endl;
    }
    else if (state == RoomState::Print_Stats)
    {
        aPlayer.PrintStats();
    }
    else if (state == RoomState::Open_Door)
    {
        std::cout << "I am opening the doors" << std::endl;
    }
}