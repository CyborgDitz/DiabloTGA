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

void GameManager::EnterMainMenu()
{
    {
        std::cout << "I am in the main menu saying the dungoeon name" << std::endl;

        {
            std::cout << "These are your choices" << std::endl;
            std::cout << "1: Enter Dungeon, 2: Cheats, 0: exit game" << std::endl;
            SetMainState();
        }

        if (mainState == MainState::Exit)
        {
            std::cout << "I am main menu choices func  ending the game" << std::endl;
        }
        else if (mainState == MainState::Play)
        {
            std::cout << "I am in the main menu choices func saying to enter the dungoen" << std::endl;
        }
        else if (mainState == MainState::Cheats_Menu)
        {
            std::cout << "I am in the main menu choices func saying the cheats" << std::endl;
        }
    }
}

void GameManager::SetMainState()
{ 
    int min = static_cast<int>(MainState::Exit);
    int choice = Library::SetInput(min, sizeof(mainState));
    mainState = static_cast<MainState>(choice);
}

void GameManager::EnterRoom(Player& aPlayer, Room& aRoom)
{
    system("cls");
    std::cout << aPlayer.GetName() << '\t' <<
        " enters the... " << '\t' <<
        aRoom.GetName() << std::endl;

    system("pause");
    aRoom.PrintStats();
}

void GameManager::RoomMenu(Room& aRoom, Player aPlayer, Enemy aEnemy)
{
    {
            Library::SayRoomMenu();
            aRoom.SetState();
        
        const Room::RoomState state = aRoom.GetRoomState();

        if (state == Room::RoomState::Exit)
        {
            std::cout << "I am the ending the game cuz Im dead I guess" << std::endl;
        }
        else if (state == Room::RoomState::Explore)
        {
            std::cout << "I am in the room menu saying whats inside it" << std::endl;
        }
        else if (state == Room::RoomState::Combat)
        {//reall want a combat class 
            CombatManager::StartCombatLoop(aRoom, aPlayer, aEnemy);
        }
    }
}


