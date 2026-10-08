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
    enum class Unlock
    {
        Exit = 0,
        Bash =1,
        Picklock =2,
        Count = 3
    };

    int GetDC(){return myDC;}
    void LockPick(int aPlayerAttribute);
    bool GetIsLocked() const {return myIsLocked;}
    Room& PickDoor(std::vector<Door>& aDoors);
    void UnlockDoor(const Player& aPlayer);
    void Bash(int aPlayerAttribute);
    void MoveToRoom(const Room& aFromRoom) const;
    Room& GetPrevRoom(){return myPrevRoom;}
    Room& GetNextRoom(){return myNextRoom;}
    
    //Room& GetNexRoom(const Room& aFromRoom) const;

private:
    Room& myPrevRoom;
    Room& myNextRoom;
    bool myIsLocked{};
    int myDC{};
};
