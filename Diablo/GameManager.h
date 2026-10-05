#pragma once
#include <vector>

#include "Cheats.h"
#include "Door.h"
#include "Enemy.h"
#include "Player.h"
#include "Room.h"
#include "Library.h"
class GameManager
{
public:
    GameManager()
    {
        //myPlayer.SetName();
        PopulateRooms(myRooms);
        PopulateDoors(myDoors);
        myCurrentRoom = &myRoom0;
        myCurrentDoor = &myDoor0;
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

    Player& GetPlayer() {return myPlayer;}
    MainState& GetMainState() {return myMainState;}
    
    Room& GetRoom1() {return myRoom1;}
    Room& GetRoom2() {return myRoom2;}
    Enemy& GetEnemy0() {return myEnemy0;}
    Enemy& GetEnemy1() {return myEnemy1;}
    std::vector<Enemy>&GetPopulation(){return myPopulation;}
  
    
    //todo vectors later
    // std::vector <Room> GetRooms() {return myRoom0s;}
    // std::vector <Door> GetDoors() {return doors;}
    
 
    void PrintEnemyStats(Enemy* aEnemyType); // todo in class
    void PrintMainMenuChoices(Player& aPlayer); // todo in class
    void PopulateRooms(std::vector<Room>& aRooms);
    void SetGameState(const MainState& aMainState){myMainState = aMainState; }
    
    void PopulateEnemies(std::vector<Enemy>& aPopulation, Enemy& aEnemyType, Room& aRoom);
    void PopulateDoors(std::vector<Door>& aDoors);
    void SetRoom();

    void SetCheatState(Player& aPlayer);
    void SetMainState();
    void GameCombat();
    // void EnterDoor(std::vector<Door>& aDoors);
    void ChooseDoor();
    void PlayGame();

private:
    
    MainState myMainState = MainState::Menu;
  CheatState myCheatState = CheatState::Count;
    Player myPlayer{6,6,6};
    Room* myCurrentRoom;
    Door* myCurrentDoor;
    
    
    Enemy myEnemy0{"BobsterMonster",1,1, };
    Enemy myEnemy1{"Big Blob",1, 2,};
    Enemy myEnemy2 {"Diablob", 666,666,};
    
    Room myRoom0{"Pit", 2,2,};
    Room myRoom1{("Shower"),2,0,};
    Room myRoom2{"Ballgame Park", 2,1,};
    
    Door myDoor0 {myRoom2,myRoom1, 5, true};
    Door myDoor1 {myRoom1,myRoom2, 20, false};
    Door myDoor2 {myRoom2,myRoom0, 0, false};
    
    
    std::vector<Enemy> myPopulation;
    std::vector<Room> myRooms;
    std::vector<Door> myDoors; 
    
   
    // todo vectors later
    // std::vector<Room> myRoom0s;
    // std::vector <Door> doors;
};
