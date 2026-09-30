#include <iostream>

#include "Enemy.h"
#include "Player.h"
#include "Room.h"

namespace CombatManager
    {
        bool IsCombatantsAlive(Player& aPlayer, Enemy& aEnemy)
        {
            bool combatantsAlive{};
            if (aPlayer.GetIsAlive() == true && aEnemy.GetIsAlive() == true)
            {
                combatantsAlive = true;
            }
            else
            {
                combatantsAlive = false;
            }


            return combatantsAlive;
        }

        void PlayerAttack(Player& aPlayer, Enemy& aEnemy)
        {
            //TODO Turn order enum could switch who attacks for 1 attack func
            Enemy& enemyTarget = aEnemy;

            const int damage = aPlayer.GetAtk();

            const char* target = aEnemy.GetName();
            std::cout << aPlayer.GetName() << " dealt " << damage << " damage to " << aEnemy.GetName() <<
                std::endl;
            enemyTarget.TakeDamage(damage);
        }

        void EnemyAttacks(Room& aRoom, Player& aPlayer, Enemy& aEnemy)
        {
            const int enemyAttacks = aRoom.getEnemiesAmount();
            //todo Bool enemis contains alive enmies in vector aka if vector empty
            if (enemyAttacks > 0 && aEnemy.GetAlive() == true)
            {
                const char* targetName = aPlayer.GetName();
                const int damageToTarget = aEnemy.GetDamage();
                const char* attackerNamer = aEnemy.GetName();

                std::cout << attackerNamer << "dealt " << damageToTarget << " damage to " << targetName
                    << std::endl;
                //todo loop per enemy in vector

                for (int i = 0; i < enemyAttacks; ++i)
                {
                    aPlayer.TakeDamage(damageToTarget);
                }
            }
        }

        void AllAttacking(Room& aRoom, Player& aPlayer, Enemy& aEnemy)
        {
            PlayerAttack(aPlayer, aEnemy);
            std::cout << "If enemy is dead return" << std::endl;
            EnemyAttacks(aRoom,aPlayer, aEnemy);
        }

        void StartCombatLoop(Room& aRoom, Player& aPlayer, Enemy& aEnemy)
        {
            if (aPlayer.GetIsAlive() && aEnemy.GetIsAlive() == true)
            {
                while (IsCombatantsAlive(aPlayer, aEnemy))
                {
                    AllAttacking(aRoom,aPlayer, aEnemy);
                }
            }
            else
            {
                std::cout << "I have no enemies" << std::endl;
            }
        }
    }