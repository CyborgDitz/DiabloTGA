#pragma once
#include "Player.h"


class Room
{
public:
    Room(const int aDoors, const int aEnemies, const char* aName)
    {
        myDoors = aDoors;
        myEnemies = aEnemies;
        myName[17] = *aName;
        if (myEnemies > 0)
        {
            myHasEnemies = true;
        }
    }
    
    enum class RoomState
    {
        Exit =0,
        Explore = 1,
        Combat = 2,
        Print_Stats = 3,
        Open_Door =4,
        Count = 5,
    };
    
    const char* GetName() const { return myName; }
    int getDoorAmount() const { return myDoors; }
    int getEnemiesAmount() const { return myEnemies; }
    void PrintStats() const;
    void EnterRoom(const Player& aPlayer);
   
    RoomState& GetRoomState()  { return myState; }
    
    void SetDoors(const int aDoors) { myDoors = aDoors; }
    void SetState();

private:
    int myRoomID {};
    int myDoors = 2;
    int myEnemies {};
    char myName[17] = "Room";
    bool myHasEnemies = false;
  
    RoomState myState = RoomState::Explore;
};
