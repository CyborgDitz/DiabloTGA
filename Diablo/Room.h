#pragma once
#include "GameManager.h"

class Room
{
public:
    Room(const int aRoomID, const int aDoors, const int aEnemies, const char aName)
    {
        myRoomID = aRoomID;
        myDoors = aDoors;
        myEnemies = aEnemies;
        myName[17] = aName;
    }
    
    enum class RoomMenu
    {
        Exit =0,
        Explore = 1,
        Combat = 2,
        Print_Stats = 3,
        Open_Door =4
    };
    const char* GetName() const { return myName; }
    int GetRoomID() const { return myRoomID; }
    int getDoorAmount() const { return myDoors; }
    RoomMenu getRoomMenu() const { return myMenu; }
    
    void SetRoomID(int aID) { myRoomID = aID; }
    void SetDoors(int aDoors) { myDoors = aDoors; }
    void PrintStats() const;
    void SetRoomState(GameManager& aGame);
    void RoomMenuStuff(GameManager& aGame);

private:
    int myRoomID {};
    int myDoors = 2;
    int myEnemies {};
    char myName[17] = "Room";
    
    RoomMenu myMenu = RoomMenu::Explore;
};
