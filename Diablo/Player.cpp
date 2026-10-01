#include "Player.h"

#include <iostream>

void Player::PrintStats() const
{
    // can I loop through my stats and print?
    // for (int i = 0; i < 3; i++)
    // {
    //     std::cout << "My health is: " << std::endl;
    // }
    std::cout << myName << "stats are : \n " <<
        "Current Health: " << myHealth << '\t' <<
        "Max Health: " << myMaxHealth << '\n' << 
        "Attack damage: " << myAtk << '\t' <<  
        "Defense: " << myDefense << '\n' <<
        "STR: " << myStr << '\t' <<
        "DEX: " << myDex << '\t' <<
        "VIT " << myVit << '\t' <<
        "Carrying Cap: " << myCarryCap << std::endl;
}
void Player::TakeDamage(const int aDamage)
{
    //todo same func for monster and myPlayer
    const int myCurrentHealth = myHealth;
    myHealth -= aDamage;
    myHealth = std::max(myHealth, 0);
    std::cout << myCurrentHealth << " takes " << aDamage << " and has " << myHealth <<  
        " health left!" <<std::endl;
    if (myHealth <= 0)
    {
        myIsAlive = false;
        std::cout << "I am dead and game ends bleh.." << std::endl;
        system("pause");
        return;
    }
    std::cout << "It is still standing!" << std::endl;
}
void Player::SetName()
{
    std::cout << "What is your name, Adventurer?: " << myName << std::endl;
    while (true)
    {
        std::cout << "Name must at least 2 characters long and only contain letters" << std::endl;
        
       std::cin.get(myName, 16);
        if (std::cin.fail())
        {
            std::cin.clear();
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

                else if (i >= 2 && myName[i] == '\0')
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    return;
                }
            }
        }
    }
}
