#pragma once
#include <vector>

#include "Room.h"

class Door
{

public:
    Door(Room& aPrevRoom, Room& aNextRoom, const int aDC, const bool aIsLocked) 
    : myPrevRoom(aPrevRoom), myNextRoom(aNextRoom)
    {
        myDC = aDC;
        myIsLocked = aIsLocked;
    }

    int GetDC(){return myDC;}
    void LockPick(int aPlayerAttribute);
    Room& PickDoor(std::vector<Door> aDoors);
    void Bash(int aPlayerAttribute);
    void MoveToRoom(std::vector<Room> aRooms, const Room& aFromRoom) const;
    Room& GetPrevRoom(){return myPrevRoom;}
    Room& GetNextRoom(){return myNextRoom;}
    
    //Room& GetNexRoom(const Room& aFromRoom) const;

private:
    Room& myPrevRoom;
    Room& myNextRoom;
    bool myIsLocked{};
    int myDC{};
};
