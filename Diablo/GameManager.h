#pragma once
#include <vector>

#include "Cheats.h"
#include "Door.h"
#include "Enemy.h"
#include "Player.h"
#include "Room.h"

class GameManager
{
public:
    enum class GameState
    {
        Exit =0,
        Play = 1,
        Cheats_Menu = 2,
        Main_Menu = 3,
    };
    enum class Cheats
    {
        None = 0,
        Cheats_Infinite_DPS = 1,
        Cheats_GodMode = 2,
        Cheats_Both = 3
    };

    Player& GetPlayer() {return player;}
    GameState GetGameState() const {return gameState;}
    Room* GetRoom(Room* aRoom) const {return aRoom;}
    Cheats GetCheats() const {return cheats;}
    Door GetDoor() const {return door;}
    static Enemy GetEnemy(Enemy& aEnemy) {return aEnemy;}
    std::vector<Enemy> GetEnemies(){return enemies;}
   
    
    void PrintEnemyStats(Enemy* aEnemy);
    int GetInput(const int aInputMin,const  int aInputMax);
    void SetGameState();
    void MainMenuStuff();
    void EnterRoom(Player& aPlayer);
    void SayName(const char* aName);
    void PrintStats(Room* aRoom);
    

private:
    
    GameState gameState = GameState::Main_Menu;
    Player player{6,6,6};
    Enemy enemy0{6,7};
    Room room0{6,7,6,(*"blabla")};
    Cheats cheats;
    Door door;
    // std::vector<Room> rooms;
    std::vector <Door> doors;
    std::vector<Enemy> enemies;
};
