#pragma once
#include <vector>

#include "Cheats.h"
#include "Door.h"
#include "Enemy.h"
#include "Item.h"
#include "Player.h"
#include "Room.h"

#include "Spell.h"

class GameManager
{
public:
    GameManager()
    {
        //myPlayer.SetName();
        PopulateRooms(myRooms);
        PopulateDoors(myDoors);
        myCurrentRoom = &myRooms[0];
        myCurrentDoor = &myDoors[0];
    }
    enum class MainState
    {
        Exit =0,
        Play = 1,
        Cheats = 2,
        Menu = 3,
        Count = 4
    };
    enum class CheatState
    {
        Exit = 0,
         InfiniteDPS = 1,
         GodMode = 2,
         BothCheats = 3,
         SayCheats = 4,
        Count = 5
     };
    enum class RoomState
    {
        Exit =0,
        OpenDoor =1,
        Combat = 2,
        Explore = 3,
        PrintStats = 4,
        Count = 5,
    };
  

    Player& GetPlayer() {return myPlayer;}
    MainState& GetMainState() {return myMainState;}
    
    Room& GetRoom1() {return myRoom1;}
    Room& GetRoom2() {return myRoom2;}
    Enemy& GetEnemy0() {return myEnemy0;}
    Enemy& GetEnemy1() {return myEnemy1;}
    std::vector<Enemy>&GetPopulation(){return myPopulation;}
    
    void PopulateRooms(std::vector<Room>& aRooms);
    void SetGameState(const MainState& aMainState){myMainState = aMainState; }
    
    void PickupItem();
    
    void PlayGame();
    void StartRoomLoop();
    void SelectRoomMenuChoices() ;
    void SetCheatState(Player& aPlayer);
    void GameCombat();
    void ChooseDoor();
    void PopulateRoom();
    void PopulateEnemies(std::vector<Enemy>& aPopulation, Enemy& aEnemyType, Room& aRoom);
    void PopulateDoors(std::vector<Door>& aDoors);
    void PrintMainMenuChoices(Player& aPlayer);
    bool isEnemiesHere() const;

    RoomState& GetRoomState()  { return myRoomState; }
    void SetRoomState(const RoomState& aState){myRoomState = aState;}
    
private:
    
    MainState myMainState = MainState::Menu;
    CheatState myCheatState = CheatState::Count;
    RoomState myRoomState = RoomState::Explore;
    Player myPlayer{10,11,12};
    Room* myCurrentRoom;
    Door* myCurrentDoor;
    
    
    
    Enemy myEnemy0{"BobsterMonster",1,1, };
    Enemy myEnemy1{"Big Blob",1, 2,};
    Enemy myEnemy2 {"Diablob", 666,666,};
  
    Door myDoor0 {myRoom2,myRoom1, 10, true};
    Door myDoor1 {myRoom1,myRoom2, 10, true};
    Door myDoor2 {myRoom2,myRoom0, 0, false};

    Item myItem0 {"Bonk Hammer", 3, 2};
    Item myItem1 {"Slime sword", 10, 5};
    Item myItem2 {"The Horn of Doom and Slimery", -100, -100};
    
    
    Chest myChest0 {"Sticky Chest", true, false, myItem0};  
    Chest myChest1 {"Sticky Chest", true, false, myItem1};
    Chest myChest2 {"Sticky Chest", true, false, myItem2};  
    
    Room myRoom0{"Pit", 2,2, true, myChest0, myItem0};
    Room myRoom1{("Shower"),2,0, true, myChest1,myItem1};
    Room myRoom2{"Ballgame Park", 2,1,false, myChest2, myItem2 };
    
    std::vector<Enemy> myPopulation;
    std::vector<Room> myRooms;
    std::vector<Door> myDoors; 
    std::vector<Item> myItems;
    // std::vector<Spell> mySpells;
    
};
