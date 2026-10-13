#include "EnemyFactory.h"

#include "Enemy.h"

EnemyFactory::EnemyFactory() : myEnemyTypes()
{
}

EnemyFactory::~EnemyFactory() { }

void EnemyFactory::Init()
{
    const int enemyBlob = static_cast<int>(enumEnemyType::Blob);
    myEnemyTypes[enemyBlob].SetName("BobsterMonster");
    myEnemyTypes[enemyBlob].SetMaxHealth(3);
    myEnemyTypes[enemyBlob].SetDefense(2);
    
    const int enemyBig = static_cast<int>(enumEnemyType::BigBlob);
    myEnemyTypes[enemyBig].SetName("Big Blob");
    myEnemyTypes[enemyBig].SetMaxHealth(10);
    myEnemyTypes[enemyBig].SetDefense(5);
    
    const int enemyDiablob = static_cast<int>(enumEnemyType::Diablob);
    myEnemyTypes[enemyDiablob].SetName("Diablob");
    myEnemyTypes[enemyDiablob].SetMaxHealth(666);
    myEnemyTypes[enemyDiablob].SetDefense(666);
}
Enemy EnemyFactory::CreateEnemy(const enumEnemyType aEnemyType)  const
{
   Enemy newEnemy (myEnemyTypes[static_cast<int>(aEnemyType)]);
    return newEnemy;
}
