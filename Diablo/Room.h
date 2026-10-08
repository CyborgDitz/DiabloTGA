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
    
   
    
    const char* GetName() const { return myName; }
    int GetDoorAmount() const { return myDoorsAmount; }
    int GetEnemiesAmount() const { return myEnemies; }
    void PrintRoomData() const;
    void PrintEnterRoom(const Player& aPlayer) const;
    void SetDoors(const int aDoors) { myDoorsAmount = aDoors; }
    
    //void SetState();

private:
    int myDoorsAmount = 2;
    int myEnemies {};
    const char* myName = "Room";
    
    
    bool myHasEnemies = false;
};
