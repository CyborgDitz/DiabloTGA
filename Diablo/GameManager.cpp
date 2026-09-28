#include "GameManager.h"

#include <iostream>
#include <ostream>

void GameManager::PrintEnemyStats(Enemy* aEnemy)
{
    {
        std::cout << "SIX SEEVEEEEN" << std::endl;
    }
}

int GameManager::SetInput(const int aInputMin,const  int aInputMax)
{
        int inputInt{};
        const int inputMin = aInputMin;
        const int inputMax = aInputMax;
    while (true)
    {

        std::cin >> inputInt;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        else if (inputMin <= inputInt && inputInt <= inputMax)
        {
            break;
        }
    }
    return inputInt;
};
void GameManager::SetGameState()
{  
   
    const int min = 0;
    //todo enum
    int choice = SetInput(min,sizeof( gameState));
    gameState = static_cast<GameState>(choice);
}
void GameManager::MainMenuStuff()
{
    {
        std::cout << "I am in the main menu saying the dungoeon name" << std::endl;
        
            {
                std::cout << "thes are the choices" << std::endl;
                std::cout << "1: Enter Dungeon, 2: Cheats, 0: exit game" << std::endl;
                SetGameState();
            }

            if (GetGameState() == GameState::Exit)
            {
                std::cout << "I am the ending the game" << std::endl;
            }
            else if (GetGameState() == GameState::Play)
            {
                std::cout << "I am in the main menu saying to enter the dungoen" << std::endl;
            }
            else if (GetGameState() == GameState::Cheats_Menu)
            {
                std::cout << "I am in the main menu saying the cheats" << std::endl;
            }
        }
}

void GameManager::EnterRoom(Player& aPlayer, Room& aRoom)
{
    Room& room = aRoom;
    
    SayName(aPlayer.GetName());
    SayName(room.GetName());
    system("pause");
    room.PrintStats();
    system("pause");
    aPlayer.PrintStats();
}

const char* GameManager::SayName(const char* aName)
{
    for (int i = 0; i < sizeof(aName); i++)
    {
        if (aName[i] == '\0')
        {
            std::cout << std::endl;
            return aName;
        }
        std::cout << aName[i];
    }
}
void GameManager::Combat(Player& aPlayer, Enemy& aEnemy, Room& aRoom)
{
    AttackEnemy(aPlayer, aEnemy);
    EnemyAttacks(aPlayer,aEnemy,aRoom);
}
void GameManager::AttackEnemy(Player& aPlayer, Enemy& aEnemy)
{
    Enemy& enemyTarget = aEnemy;
    
    const int damage = aPlayer.DealDamage();
    const char* targetName = aPlayer.GetName();
    const char* attackerNamer = aEnemy.GetName();
    
    enemyTarget.TakeDamage(damage);
    std::cout << SayName(attackerNamer)<< "dealt " << damage << "damage to " << SayName(targetName)<< std::endl;
}
void GameManager::EnemyAttacks(Player& aPlayer, Enemy& aEnemy, const Room& aRoom)
{
    const int damage = aEnemy.DealDamage();
    const char* targetName = aPlayer.GetName();
    const char* attackerNamer = aEnemy.GetName();
    
    const int enemyAttacks = aRoom.getEnemiesAmount();
    std::cout << SayName(attackerNamer)<< "dealt " << damage << "damage to " << SayName(targetName)<< std::endl;
    //todo loop per enemy in vector
   
    for (int i = 0; i < enemyAttacks; ++i)
    {
        aPlayer.TakeDamage(aEnemy.DealDamage());
    }
}

void GameManager::SetRoomState(Room& aRoom)
{
    Room rooms = aRoom;
    const int min = 0;
    //todo enum
    int choice = SetInput(min,sizeof(rooms ));
    Room::RoomState state = static_cast<Room::RoomState>(choice);
    rooms.SetRoomState(state);
}

void GameManager::RoomStateStuff(Room& aRoom)
{
    {
        const Room::RoomState state = aRoom.GetRoomState();
        std::cout << "I am in the main menu saying the dungoeon name" << std::endl;
        
        {
            std::cout << "thes are the choices" << std::endl;
            std::cout << "1: Explore\t 2: Attack the Monsters!\t 3: See your stats\t 4: Open Door "  << std::endl;
            SetRoomState(aRoom);
        }

        if (state == Room::RoomState::Exit)
        {
            std::cout << "I am the ending the game cuz im dead i guess" << std::endl;
        }
        else if (state ==  Room::RoomState::Explore)
        {
            std::cout << "I am in the room menu saying whats inside it" << std::endl;
        }
        else if (state ==  Room::RoomState::Combat)
        {
            std::cout << "pow pow pow" << std::endl;
        }
    }
}
