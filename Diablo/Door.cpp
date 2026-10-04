#include "Door.h"

#include <iostream>
#include <ostream>
#include <vector>

#include "Library.h"

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
Room& Door::PickDoor(std::vector<Door> aDoors)
{
    const int input =  Library::SetInput(1, aDoors.size())-1;
    std::cout << "I didnt go int" << aDoors[input].GetPrevRoom().GetName() << std::endl;
    std::cout << "I am going into " << aDoors[input].GetNextRoom().GetName() << std::endl;
    Room& room = aDoors[input].GetNextRoom();
    std::cout << "debug get dc from doors " << aDoors[input].GetDC() << std::endl;
    return room;
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
