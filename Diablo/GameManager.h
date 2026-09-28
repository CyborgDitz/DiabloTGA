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
    GameState& GetGameState() {return gameState;}
    Room& GetRoom() {return room0;}
    Cheats& GetCheats()  {return cheats;}
    Enemy& GetEnemy() {return enemy0;}
    
    //todo vectors later
    // std::vector <Room> GetRooms() {return rooms;}
    // std::vector <Door> GetDoors() {return doors;}
    // std::vector<Enemy> GetEnemies(){return enemies;}
   
    void SetGameState();
    //void SetRoom(std::vector<Room>* aRoom);
    
    void PrintEnemyStats(Enemy* aEnemy);
    int SetInput(const int aInputMin,const  int aInputMax);
    void MainMenuStuff();
    void EnterRoom(Player& aPlayer, Room& aRoom);
    const char* SayName(const char* aName);
    void Combat(Player& aPlayer, Enemy& aEnemy, Room& aRoom);
    void AttackEnemy(Player& aPlayer, Enemy& aEnemy);
    void EnemyAttacks(Player& aPlayer, Enemy& aEnemy, const Room& aRoom);
    
    void PrintStats(Room* aRoom);
    void SetRoomState(Room& aRoom);
    void RoomStateStuff(Room& aRoom);

private:
    
    GameState gameState = GameState::Main_Menu;
    Player player{6,6,6};
    Enemy enemy0{6,7, "bob"};
    Room room0{6,7,6,("blab")};
    Cheats cheats;
    Door door;
    // todo vectors later
    // std::vector<Room> rooms;
    // std::vector <Door> doors;
    // std::vector<Enemy> enemies;
};
