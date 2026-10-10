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
        PopulateRooms();
        PopulateDoors();
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
        CastMagic = 3,
        Explore = 4,
        PrintStats = 5,
        Count = 6,
    };
  

    Player& GetPlayer() {return myPlayer;}
    MainState& GetMainState() {return myMainState;}
    
    
    std::vector<Enemy>&GetPopulation(){return myPopulation;}
    
    void PopulateRooms();
    void SetGameState(const MainState& aMainState){myMainState = aMainState; }
  
    RoomState& GetRoomState()  { return myRoomState; }
    void SetRoomState(const RoomState& aState){myRoomState = aState;}
   
    void PlayGame();
    void StartRoomLoop();

    void SelectRoomMenuChoices();
    void SetCheatState(Player& aPlayer);
    void GameCombat();
    void ChooseDoor();
    void PopulateRoom();
    void PopulateEnemies(std::vector<Enemy>& aPopulation, Enemy& aEnemyType, Room& aRoom);
    void PopulateDoors();
   
    void PrintMainMenuChoices(Player& aPlayer);
    bool isEnemiesHere() const;
    

    
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
  
    Door myDoor0 { myRoom2,myRoom1,10, true};
    Door myDoor1 {myRoom0,myRoom2, 10, true};
    Door myDoor2 {myRoom1, myRoom0 ,0, false};

    Item myItem0 {"Bonk Hammer", 3, 2};
    Item myItem1 {"Slime sword", 10, 5};
    Item myItem2 {"The Horn of Doom and Slimery", -100, -100};
    
    Spell mySpell0 {"BoomBadaboom", 3,3, true};
    Spell mySpell1 {"Big Bonk", 1,2, true };
    Spell mySpell2 {"The Big Blob Bang", 9999,9999, true};
    Room myRoom0{"Pit", 2,2, true, true, myItem0, mySpell0};
    Room myRoom1{("Shower"),2,0, true,true, myItem1, mySpell1};
    Room myRoom2{"Ballgame Park", 2,1, false, true,  myItem2, mySpell2};
    
    std::vector<Enemy> myPopulation;
    std::vector<Room> myRooms;
    std::vector<Door> myDoors; 
    std::vector<Item> myItems;
    
};
