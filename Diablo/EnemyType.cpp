#include "EnemyType.h"

#include <algorithm>
#include <iostream>

EnemyType::EnemyType() { }

EnemyType::EnemyType( const char* aName, const int aMaxHealth, const int aMyAtk)
{
    strcpy_s(myName, aName);
    myMaxHealth = aMaxHealth;
    myHealth = myMaxHealth;
    myAtk = aMyAtk;
}
