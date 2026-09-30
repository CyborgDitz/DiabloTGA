#include <iostream>

#include "GameManager.h"

int main(int argc, char* argv[])
{
    GameManager game;
    Player& player = game.GetPlayer();
    Room& room = game.GetRoom();
    Enemy& enemy = game.GetEnemy();
    GameManager::MainState& mainState = game.GetMainState();

    bool isMenu = true;
    while (isMenu && mainState != GameManager::MainState::Exit && player.GetIsAlive())
    {
        player.SetName();
        game.EnterMainMenu();
        {
            std::cout << "Welcome to the Pits of Eternal Goob, " << player.GetName() << std::endl;
        }
        while (mainState == GameManager::MainState::Play && player.GetIsAlive())
        {
            game.EnterRoom(player, room);
            game.RoomMenu(room, player, enemy);
        } 
        system("pause");
        std::cout << "I am outside of the room\n" << std::endl;
 
       
        {
            system("pause");
        }
    }
    return 0;
}
