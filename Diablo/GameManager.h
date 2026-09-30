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

    Player& GetPlayer() {return player;}
    MainState& GetMainState() {return mainState;}
    Room& GetRoom() {return room0;}
    Cheats& GetCheats()  {return cheats;}
    Enemy& GetEnemy() {return enemy0;}
  
    
    //todo vectors later
    // std::vector <Room> GetRooms() {return rooms;}
    // std::vector <Door> GetDoors() {return doors;}
    // std::vector<Enemy> GetEnemies(){return enemies;}

 
    //void SetRoom(std::vector<Room>* aRoom);

 
    void PrintEnemyStats(Enemy* aEnemy);
    void PrintStats(Room* aRoom);
    void EnterMainMenu();
    void EnterRoom(Player& aPlayer, Room& aRoom);
   void SetGameState(MainState& aMainState){mainState = aMainState; }
    void RoomMenu(Room& aRoom, Player aPlayer, Enemy aEnemy);

    void SetMainState();
private:
    
    MainState mainState = MainState::Main_Menu;
    Player player{6,6,6};
    Enemy enemy0{1,1, "BobsterMonster"};
    Room room0{6,7,6,("blab")};
    Cheats cheats {};
    Door door {};
   
    // todo vectors later
    // std::vector<Room> rooms;
    // std::vector <Door> doors;
    std::vector<Enemy> enemies;
};
