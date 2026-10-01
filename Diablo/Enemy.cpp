#include "Enemy.h"

#include <algorithm>
#include <iostream>
#include <ostream>

void Enemy::TakeDamage(const int aDamage)
{
    const int myCurrentHealth = myHealth;
    myHealth -= aDamage;
    myHealth = std::max(myHealth, 0);
    std::cout << myCurrentHealth << " takes " << aDamage << " and has " << myHealth <<  
        " health left!" <<std::endl;
    if (myHealth <= 0)
    {
        myIsAlive = false;
        std::cout << myName << " is dead and removed from vector or something" << std::endl;
        system("pause");
        return;
    }
    std::cout << "It is still standing!" << std::endl;
}
