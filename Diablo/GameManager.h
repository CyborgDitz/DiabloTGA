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
        myPlayer.SetName();
        PopulateRooms(myRooms);
        PopulateDoors(myDoors);
       
    }
    enum class MainState
    {
        Exit =0,
        Play = 1,
        Cheats_Menu = 2,
        Main_Menu = 3,
        Count = 4
    };
    enum class CheatState
    {
        Exit = 0,
         Infinite_DPS = 1,
         GodMode = 2,
         BothCheats = 3,
         NoCheats = 4,
        Count = 5
     };

    Player& GetPlayer() {return myPlayer;}
    MainState& GetMainState() {return myMainState;}
   
    Room& GetRoom0() {return myRoom0;}
    Room& GetRoom1() {return myRoom1;}
    Room& GetRoom2() {return myRoom2;}
    Enemy& GetEnemy0() {return myEnemy0;}
    Enemy& GetEnemy1() {return myEnemy1;}
    std::vector<Enemy>&GetPopulation(){return myPopulation;}
  
    
    //todo vectors later
    // std::vector <Room> GetRooms() {return myRoom0s;}
    // std::vector <Door> GetDoors() {return doors;}

 
    //void SetRoom(std::vector<Room>* aRoom);

 
    void PrintEnemyStats(Enemy* aEnemyType); // todo in class
    void PrintMainMenuChoices(Player& aPlayer); // todo in class
    void PopulateRooms(std::vector<Room>& aRooms);
    void SetGameState(const MainState& aMainState){myMainState = aMainState; }
    
    void PopulateEnemies(std::vector<Enemy>& aPopulation, Enemy& aEnemyType, Room& aRoom);
    void PopulateDoors(std::vector<Door>& aDoors);
    
    void SetCheatState(Player& aPlayer);
    void SetMainState();
    void GameCombat();
    void EnterDoor(std::vector<Door>& aDoors);
    Room& PickDoor();
    void PlayGame();

private:
    
    MainState myMainState = MainState::Main_Menu;
  CheatState myCheatState = CheatState::Count;
    Player myPlayer{6,6,6};
    
    Enemy myEnemy0{"BobsterMonster",1,1, };
    Enemy myEnemy1{"Big Blob",1, 2,};
    Enemy myEnemy2 {"Diablob", 666,666,};
    
    Room myRoom0{"Pit", 2,1,};
    Room myRoom1{("Shower"),2,2,};
    Room myRoom2{"Ballgame Park", 2,1,};
    
    Door myDoor0 {myRoom1,myRoom2, 30, true};
    Door myDoor1 {myRoom2,myRoom0, 20, true};
    Door myDoor2 {myRoom0,myRoom1, 0, false};
    
    std::vector<Enemy> myPopulation;
    std::vector<Room> myRooms;
    std::vector<Door> myDoors; 
    
   
    // todo vectors later
    // std::vector<Room> myRoom0s;
    // std::vector <Door> doors;
};
