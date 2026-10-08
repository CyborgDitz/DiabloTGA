#pragma once
#include <vector>
#include <vector>

#include "Enemy.h"
#include "Library.h"
#include "Player.h"


class Room
{
public:
    Room(const char* aName, const int aDoorsAmount, const int aEnemies, int aSpell )
    {
        myName = aName;
        myDoorsAmount = aDoorsAmount;
        myEnemies = aEnemies;
        if (myEnemies > 0)
        {
            myHasEnemies = true;
        }mySpell = static_cast<Spell>(aSpell);
    }
    
    enum class Spell
    {
        None = 0,
        Fire = 1,
        Ice = 2,
        Blob = 3,
        Count = 4
    };
    const char* GetName() const { return myName; }
    int GetDoorAmount() const { return myDoorsAmount; }
    int GetEnemiesAmount() const { return myEnemies; }
    void PrintRoomData(std::vector<Enemy>* aPopulatiion) const;
    void PrintEnterRoom(const Player& aPlayer) const;
    void SetDoors(const int aDoors) { myDoorsAmount = aDoors; }
    
    Spell& GetSpell() { return mySpell; }
    void SetSpell(Spell aSpell) { mySpell = static_cast<Spell>(Library::SetInput(static_cast<int>(Spell::Fire),
        static_cast<int>(Spell::Count)));}
    //void SetState();

private:
    Spell mySpell = Spell::None;
    int myDoorsAmount = 2;
    int myEnemies {};
    const char* myName = "Room";
    
    
    bool myHasEnemies = false;
};
