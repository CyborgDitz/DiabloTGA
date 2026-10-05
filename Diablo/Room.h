#pragma once
#include "Player.h"


class Room
{
public:
    Room(const char* aName, const int aDoorsAmount, const int aEnemies )
    {
        myName = aName;
        myDoorsAmount = aDoorsAmount;
        myEnemies = aEnemies;
        if (myEnemies > 0)
        {
            myHasEnemies = true;
        }
    }
    
    enum class RoomState
    {
        Exit =0,
        OpenDoor =1,
        Combat = 2,
        Explore = 3,
        PrintStats = 4,
        Count = 5,
    };
    
   int GetStateLength () const { return myStateLength; }
    const char* GetName() const { return myName; }
    int GetDoorAmount() const { return myDoorsAmount; }
    int GetEnemiesAmount() const { return myEnemies; }
    void ExploreRoom() const;
    void PrintEnterRoom(const Player& aPlayer) const;
    void RoomMenuChoices(const Player& aPlayer) const;
    

    RoomState& GetRoomState()  { return myState; }
    void SetRoomState(const RoomState& aState){myState = aState;}
    void SetDoors(const int aDoors) { myDoorsAmount = aDoors; }
    
    //void SetState();

private:
    int myDoorsAmount = 2;
    int myEnemies {};
    const char* myName = "Room";
    const int myStateMin = static_cast<int>(RoomState::Exit);
    const int myStateLength = static_cast<int>(RoomState::Count);
    bool myHasEnemies = false;
    RoomState myState = RoomState::Explore;
};
