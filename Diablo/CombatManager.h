#include "Enemy.h"
#include "Player.h"
#include "Room.h"
#include <iostream>

namespace CombatManager
    {
        bool IsCombatantsAlive(Player& aPlayer, Enemy& aEnemy);

        void PlayerAttack(Player& aPlayer, Enemy& aEnemy);
        

       void EnemyAttacks(Room& aRoom, Player& aPlayer, Enemy& aEnemy);
        

        void AllAttacking(Room& aRoom, Player& aPlayer, Enemy& aEnemy);

       void StartCombatLoop(Room& aRoom, Player& aPlayer, Enemy& aEnemy);
    }