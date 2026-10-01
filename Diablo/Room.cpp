#include "Room.h"
#include <iostream>
#include "Library.h"


void Room::SetState()
{
    const int minInput = static_cast<int>(RoomState::Exit);
    const int maxInput = static_cast<int>(RoomState::Count);
    while (true)
    {
        int input = Library::SetInput(minInput, sizeof(myState));

        if (minInput <= input && input < maxInput)
        {
            myState = static_cast<RoomState>(input);
            break;
        }
        else
        {
            std::cout << "Outside of range! Range is : " << minInput << " to " << maxInput << std::endl;
        }
    }
}

void Room::PrintStats() const
{
    std::cout << "The myRoom0 has: " << std::endl;
    std::cout << myDoors << " doors! " << std::endl;
    if (myHasEnemies == true)
    {
        std::cout << "There are " << myEnemies << " Enemies!! Watch out! " << std::endl;
    }
    else
    {
        std::cout << myEnemies << " The myRoom0 has no monsters! " << std::endl;
    }

    std::cout << "If I had loot I would say it here :( \n" << std::endl;
}

void Room::EnterRoom(const Player& aPlayer)
{
        system("cls");
        std::cout << aPlayer.GetName() << '\t' <<
            " enters the... " << '\t' <<
            myName << '\n' << std::endl;
}
