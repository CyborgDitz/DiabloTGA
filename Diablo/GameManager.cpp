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
    std::cout << "myRoom0 stats yo" << aRoom << std::endl;
}

void GameManager::EnterMainMenu(Player& aPlayer)
{
    {
        std::cout << "Welcome to the Pits of Eternal Goob, " << aPlayer.GetName() << ' n'
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

void GameManager::PlayGame()
{
    bool isMenu = true; //mainstate enum menu
    myPlayer.SetName();

    while (GetMainState() != GameManager::MainState::Exit && isMenu && myPlayer.GetIsAlive())
    {
        EnterMainMenu(myPlayer);
        SetGameState(static_cast<MainState>(Library::SetInput(0,5)));
        while (myPlayer.GetIsAlive() && isMenu)
        {
            if (GetMainState() == GameManager::MainState::Exit)
            {
                std::cout << "I am main menu choices func  ending the game" << std::endl;
            }
            else if (GetMainState() == GameManager::MainState::Play)
            {
                {
                    //room 0
                    myRoom0.EnterRoom(myPlayer);
                    myRoom0.PrintStats();
                    myRoom0.SetState();
                }

                {
                    //room 1
                    myRoom1.EnterRoom(myPlayer);
                    myRoom1.PrintStats();
                    myRoom1.SetState();
                }

                {
                    myRoom2.EnterRoom(myPlayer);
                    myRoom2.PrintStats();
                    myRoom2.SetState();
                }
                Library::SayRoomMenu();
                {
                    const Room::RoomState state = myRoom0.GetRoomState();
                    if (state == Room::RoomState::Exit)
                    {
                        std::cout << "I am the ending the game cuz Im dead I guess" << std::endl;
                    }
                    else if (state == Room::RoomState::Explore)
                    {
                        std::cout << "I am in the myRoom0 menu saying whats inside it" << std::endl;
                    }
                    else if (state == Room::RoomState::Combat)
                    {
                        //combat!
                        while (myPlayer.GetIsAlive() && myEnemies.size() > 0)
                        {
                            std::cout << "pick a target " << std::endl;

                            int target = Library::SetInput(0, myEnemies.size());
                            myEnemies[target].TakeDamage(myPlayer.GetIsAlive());

                            if (myEnemies[target].GetIsAlive() == false)
                            {
                                myEnemies.erase(myEnemies.begin() + target);
                            }
                            for (int i = 0; i < myEnemies.size(); i++)
                            {
                                myPlayer.TakeDamage(myEnemies[i].GetDamage());
                            }
                            // myPlayer.TakeDamage(enemy.GetDamage());
                        }
                    }
                    else if (GetMainState() == GameManager::MainState::Cheats_Menu)
                    {
                        std::cout << "I am in the main menu choices func saying the cheats" << std::endl;
                    }
                }


                system("pause");
                std::cout << "I am outside of the room\n" << std::endl;
            }
        }
    }
}
