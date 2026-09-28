#include "Player.h"

#include <iostream>

void Player::PrintStats()
{
    // can I loop through my stats and print?
    // for (int i = 0; i < 3; i++)
    // {
    //     std::cout << "My health is: " << std::endl;
    // }
    std::cout << "Current Health: " << myHealth << std::endl;
    std::cout << "Max Health: " << myMaxHealth << std::endl;
    std::cout <<  "Attack damage: " <<myAtk << std::endl;
    std::cout << "Defense: " <<myDefense << std::endl;
    std::cout << "STR: " <<myStr << std::endl;
    std::cout << "DEX: " << myDex << std::endl;
    std::cout << "VIT " << myVit << std::endl;
    std::cout << "Carrying Cap: " << myCarryCap << std::endl;
}
void Player::SetName()
{
    
    while (true)
    {
        std::cout << "Name must at least 2 characters long and only contain letters" << std::endl;
        std::cin.get(myName, 16);
        if (std::cin.fail())
        {  std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "errorr brrr" << std::endl;
        }
        else
        {
            for (int i = 0; i < sizeof(myName); i++)
            {
              
                if ((myName[i] > 'z' && myName[i] < 'a' || myName[i] < 'A' && myName[i] > 'Z'))
                {
                    break;
                }
                
                else if ( i >= 2 && myName[i] == '\0' )
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    return;
                }
                
            }
        }
                
    }
}
