#include "Enemy.h"

#include <algorithm>
#include <iostream>
#include <ostream>

Enemy::Enemy(const EnemyType& aEnemyType) : myHealth(0), myMaxHealth(0), myAtk(0), myDefense(0),
                                            myEnemyType(&aEnemyType) { }

void Enemy::TakeDamage(const int aDamage)
{
    const char* myName = GetName();
    const int myCurrentHealth = myHealth;
    myHealth -= aDamage;
    myHealth = std::max(myHealth, 0);
    std::cout << myName<< "has currently " << myCurrentHealth << " health\n" <<
    " and takes " << aDamage << ". Now has " << myHealth <<  
        " health left!" <<std::endl;
    if (myHealth <= 0)
    {
        myIsAlive = false;
        std::cout << myName << " is dead and removed from vector or something \n " << std::endl;
        return;
    }
    std::cout << "It is still standing!" << std::endl;
}
void Enemy::PrintStats() const
{
    std::cout << "The enemy: "<< GetName() << " stats are : \n " <<
        "HP: " << myHealth << '\t' <<
        "MaxHP: " << myMaxHealth << '\n' << 
        "Atk: " << myAtk << '\t' <<  
        "Def: " << myDefense << '\n' << std::endl;
}