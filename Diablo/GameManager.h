#pragma once
#include <vector>

#include "Enemy.h"
#include "Player.h"

class GameManager
{
public:
    Player GetPlayer(){return player;}
    //Enemy GetEnemy(Enemy aEnemy){return enemies[aEnemy];}
    
    void PrintEnemyStats(Enemy* aEnemy);
private:
    
    Player player{6,6,6};
    Enemy enemy0{6,7};
    std::vector<Enemy> enemies;
};
