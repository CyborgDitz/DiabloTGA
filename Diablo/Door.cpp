#include "Door.h"

#include <iostream>
#include <ostream>
#include <vector>

void Door::LockPick(const int aPlayerAttribute)
{
    if (aPlayerAttribute > myDC )
    {
        std::cout << "The lock clicks open!" << std::endl; 
        myIsLocked = false;
    }
    else
    {
        std::cout << "The lock is stll closed!" << std::endl;
    }
}
void Door::Bash(const int aPlayerAttribute)
{
    if (aPlayerAttribute > myDC )
    {
        std::cout << "The lock is bashed broken!" << std::endl; 
        myIsLocked = false;
    }
    else
    {
        std::cout << "The lock is stll closed!" << std::endl;
    }
}

void Door::MoveToRoom(std::vector<Room> aRooms, const Room& aFromRoom) const
{
    if (aFromRoom.GetName() == myPrevRoom.GetName())
    {
        std::cout << "Door exited! " << myPrevRoom.GetName() << std::endl;
        
        std::cout << "Door entered! " << myNextRoom.GetName() << std::endl;
        
    }
    else
    {
        std::cout << "Door entered! " << myNextRoom.GetName() << std::endl;
        std::cout << "Door exited! " << myPrevRoom.GetName() << std::endl;
    }
    
}
