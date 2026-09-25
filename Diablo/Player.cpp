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
