#pragma once
#include <vector>
#include "Door.h"
#include "Enemy.h"
#include "Player.h"
#include "Room.h"
#include "Library.h"
class GameManager
{
public:
    enum class MainState
    {
        Exit =0,
        Play = 1,
        Cheats_Menu = 2,
        Main_Menu = 3,
        Count = 4
    };
    enum class Cheats
    {
        None = 0,
        Cheats_Infinite_DPS = 1,
        Cheats_GodMode = 2,
        Cheats_Both = 3,
        Count = 4
    };

    Player& GetPlayer() {return myPlayer;}
    MainState& GetMainState() {return myState;}
    Room& GetRoom() {return myRoom0;}
    Cheats& GetCheats()  {return myCheats;}
    Enemy& GetEnemy() {return myEnemy0;}
    std::vector<Enemy>&GetPopulation(){return myEnemyPopulation;}
  
    
    //todo vectors later
    // std::vector <Room> GetRooms() {return rooms;}
    // std::vector <Door> GetDoors() {return doors;}

 
    //void SetRoom(std::vector<Room>* aRoom);

 
    void PrintEnemyStats(Enemy* aEnemy);
    void PrintStats(Room* aRoom);
    void EnterMainMenu(Player& aPlayer);
   void SetGameState(const MainState& aMainState){myState = aMainState; }
    
    void PopulateEnemies(std::vector<Enemy>& aPopulation, Enemy& aEnemy);

    void SetMainState();
private:
    
    MainState myState = MainState::Main_Menu;
    Player myPlayer{6,6,6};
    Enemy myEnemy0{1,1, "BobsterMonster"};
    Enemy myEnemy1 {1, 1,"asshole"};
    Room myRoom0{6,7,6,("blab")};
    Cheats myCheats {};
    Door myDoor {};
    std::vector<Enemy> myEnemyPopulation;
    
   
    // todo vectors later
    // std::vector<Room> rooms;
    // std::vector <Door> doors;
};
