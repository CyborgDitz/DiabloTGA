#include <iostream>

#include "GameManager.h"

int main(int argc, char* argv[])
{
    GameManager game;
    Player& player = game.GetPlayer();
    Room& room = game.GetRoom();
    Enemy& enemy = game.GetEnemy();
    bool isMenu = true;
    game.SayName(enemy.GetName());
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
            
            game.EnterRoom(player, room);
           
            game.Combat(player,enemy, room);
            
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
