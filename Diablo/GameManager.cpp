#include "GameManager.h"

#include <iostream>
#include <ostream>

void GameManager::PrintEnemyStats(Enemy* aEnemy)
{
    {
        std::cout << "SIX SEEVEEEEN" << std::endl;
    }
}

int GameManager::GetInput(const int aInputMin,const  int aInputMax)
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
    int choice = GetInput(min,sizeof( gameState));
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

void GameManager::EnterRoom(Player& aPlayer)
{
    Room roomID = room0;
    
    SayName(aPlayer.GetName());
    SayName(roomID .GetName());
    system("pause");
    roomID .PrintStats();
    system("pause");
    aPlayer.PrintStats();
}
void GameManager::SayName(const char* aName)
{
    for (int i = 0; i < sizeof(aName); i++)
    {
        if (aName[i] == '\0')
        {
            std::cout << std::endl;
            return;
        }
        std::cout << aName[i];
    }
}


