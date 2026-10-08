#include "Player.h"

#include <iostream>

void Player::PrintStats() const
{
    std::cout << myName << "stats are : \n " <<
        "Current HP: " << myHealth << '\t' <<
        "MaxHP: " << myMaxHealth << '\n' << 
        "Atk: " << myAtk << '\t' <<  
        "Def: " << myDefense << '\n' << 
        "STR: " << myStr << '\t' <<
        "DEX: " << myDex << '\t' <<
        "VIT " << myVit << '\t' <<
        "Carrying Cap: " << myCarryCap << '\n' <<std::endl;
}
void Player::TakeDamage(const int aDamage)
{
    //todo same func for monster and myPlayer
    const int myCurrentHealth = myHealth;
    myHealth -= aDamage;
    myHealth = std::max(myHealth, 0);
    std::cout << "Player " << myName << " has currently " << myCurrentHealth << " health\n" <<
       " and takes " << aDamage << ". Now has " << myHealth <<  
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
/
