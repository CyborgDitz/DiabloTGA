#include <iostream>

#include "GameManager.h"

int main(int argc, char* argv[])
{   
    GameManager game;
    Player& player = game.GetPlayer();
    Room& room = game.GetRoom();
    Enemy& enemy = game.GetEnemy();
    std::vector<Enemy>& population = game.GetPopulation();
    
    population.push_back(enemy);
    bool isMenu = true; //mainstate enum menu
    player.SetName();
    
    while (game.GetMainState() != GameManager::MainState::Exit && isMenu && player.GetIsAlive())
    {
        game.EnterMainMenu(player);
        game.SetGameState(game.GetMainState());
        while (player.GetIsAlive() && isMenu)
        {
            if (game.GetMainState() == GameManager::MainState::Exit)
            {
                std::cout << "I am main menu choices func  ending the game" << std::endl;
            }
            else if (game.GetMainState() == GameManager::MainState::Play)
            {
                room.EnterRoom(player);
                room.PrintStats();
                Library::SayRoomMenu();
                room.SetState();
                {
                    const Room::RoomState state = room.GetRoomState();

                    if (state == Room::RoomState::Exit)
                    {
                        std::cout << "I am the ending the game cuz Im dead I guess" << std::endl;
                    }
                    else if (state == Room::RoomState::Explore)
                    {
                        std::cout << "I am in the room menu saying whats inside it" << std::endl;
                    }
                    else if (state == Room::RoomState::Combat)
                    {
                        //enum and vector empty?
                        while (player.GetIsAlive() && enemy.GetIsAlive())
                        {
                            player.TakeDamage(enemy.GetDamage());
                            enemy.TakeDamage(player.GetIsAlive());
                        }
                    }
                }
            }
            else if (game.GetMainState() == GameManager::MainState::Cheats_Menu)
            {
                std::cout << "I am in the main menu choices func saying the cheats" << std::endl;
            }
        }
        system("pause");
        std::cout << "I am outside of the room\n" << std::endl;
        {
            system("pause");
        }
    }
    return 0;
}
