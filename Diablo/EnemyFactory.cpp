// #include "EnemyFactory.h"
//
// void EnemyFactory::Init()
// {
//     const int itemHammer = static_cast<int>(enumEnemyType::Hammer);
//     myEnemyTypes[itemHammer].SetName("Blob Hammer");
//     myEnemyTypes[itemHammer].SetMainMod(3);
//     myEnemyTypes[itemHammer].SetSecondModifier(2);
//     
//     const int itemSword = static_cast<int>(enumEnemyype::Sword);
//     myEnemyTypes[itemSword].SetName("Slime sword");
//     myEnemyTypes[itemSword].SetMainMod(10);
//     myEnemyTypes[itemSword].SetSecondModifier(5);
//     
//     const int itemHorn = static_cast<int>(enumEnemyype::Horn);
//     myEnemyTypes[itemHorn].SetName("The Horn of Doom and Slimery");
//     myEnemyTypes[itemHorn].SetMainMod(100);
//     myEnemyTypes[itemHorn].SetSecondModifier(100);
// }
// Enemy EnemyFactory::CreateItem(const enumEnemyType aEnemyype)  const
// {
//    Enemy newEnemy (myEnemyTypes[static_cast<int>(aEnemyType)]);
//     return newEnemy;
// }
