
#include <iostream>

#include "GameManager.h"

int main(int argc, char* argv[])
{
    GameManager game;
    bool isMenu = false;
    game.GetPlayer().PrintStats();
    while (isMenu)
    {
        {
        std::cout << "I am in the main menu saying the dungoeon name" << std::endl;
        std::cout << "I am in the main menu saying to enter the dungoen" << std::endl;
        std::cout << "I am in the main menu saying the cheats" << std::endl;
        std::cout << "I am the ending the game" << std::endl;
            system("pause");
        std::cout << "I am input and write that i am the input choice\n" << std::endl;
        system("pause");
            
        }
        {
            std::cout << "Player writes name as I enter the dungeon\n" << std::endl;
            system("pause");
        }
        {
            std::cout << "I enter the room" << std::endl;
            system("pause");
           std::cout << "I am printing the room name" << std::endl;
            std::cout << "I am printing the room monsters" << std::endl;
            std::cout << "I am printing the loot and doors" << std::endl;
            std::cout << "I am printing the player stats" << std::endl;
        std::cout << "I am printing of room choice inputs\n" << std::endl;
            system("pause");
        std::cout << "I am input and write that i am the input choice\n" << std::endl;
        system("pause");
        }
        
        
        
    }
    return 0;
}
