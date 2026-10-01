#include "GameManager.h"
#include <iostream>
#include <ostream>
#include "Library.h"

void GameManager::PrintEnemyStats(Enemy* aEnemy)
{
    {
        std::cout << "SIX SEEVEEEEN" << aEnemy << std::endl;
    }
}

void GameManager::PrintStats(Room* aRoom)
{
    std::cout << "room stats yo" << aRoom << std::endl;
}

void GameManager::EnterMainMenu(Player& aPlayer)
{
    {
        std::cout << "Welcome to the Pits of Eternal Goob, "  <<aPlayer.GetName() << ' n'
                     << "GGG_________OOO____OOO____BBB " << std::endl;
        {
            std::cout << "These are your choices" << std::endl;
            std::cout << "1: Enter Dungeon, 2: Cheats, 0: exit game" << std::endl;
        }
    }
}

void GameManager::SetMainState()
{ 
    int min = static_cast<int>(MainState::Exit);
    int choice = Library::SetInput(min, sizeof(myState));
    myState = static_cast<MainState>(choice);
}