#pragma once


class Room
{
public:
    Room(const int aRoomID, const int aDoors, const int aEnemies, const char* aName)
    {
        myRoomID = aRoomID;
        myDoors = aDoors;
        myEnemies = aEnemies;
        myName[17] = *aName;
    }
    
    enum class RoomState
    {
        Exit =0,
        Explore = 1,
        Combat = 2,
        Print_Stats = 3,
        Open_Door =4
    };
    const char* GetName() const { return myName; }
    int getDoorAmount() const { return myDoors; }
    int getEnemiesAmount() const { return myEnemies; }
    RoomState GetRoomState() const { return myMenu; }
   
    void SetDoors(int aDoors) { myDoors = aDoors; }
    void PrintStats() const;
    void SetRoomState(RoomState& aMenu) { myMenu = aMenu; }

private:
    int myRoomID {};
    int myDoors = 2;
    int myEnemies {};
    char myName[17] = "Room";
    
    RoomState myMenu = RoomState::Explore;
};
