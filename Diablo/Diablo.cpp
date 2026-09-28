#include <iostream>

#include "GameManager.h"

int main(int argc, char* argv[])
{
    GameManager game;
    bool isMenu = true;
    // game.GetPlayer().PrintStats();
    while (isMenu && game.GetGameState() != GameManager::GameState::Exit)
    {
        game.MainMenuStuff();
        {
            std::cout << "Player writes name as I enter the dungeon\n" << std::endl;
            system("pause");
        }
        if (game.GetGameState() == GameManager::GameState::Play)
        {
            std::cout << "I enter the room" << std::endl;
             game.EnterRoom(game.GetPlayer());
            
        }
        {
            system("pause");
            
            std::cout << "I am printing of room choice inputs\n" << std::endl;
            system("pause");
            std::cout << "I am input and write that i am the input choice\n" << std::endl;
            system("pause");
        }
    }
    return 0;
}
