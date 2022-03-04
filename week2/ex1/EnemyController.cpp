#include "EnemyController.h"
#include "Enemy.h" // to actualy use the field Enemy declared in the header by forward declaration, we use the field here

void EnemyController::Init(int maximumEnemies, int step, Point initialLocation)
{
    enemies         = new Enemy[maximumEnemies];
    curent_enemies  = 0;
    stepSize = step;
    startinLocation = initialLocation;
    maxim_enemies   = maximumEnemies;
    
}

void EnemyController::Uninit()
{
    delete[] enemies;
    
}

void EnemyController::Move()
{
    if (curent_enemies > 0)
    {
        for (int i = 0; i <= curent_enemies; i++)
        {
            enemies[i].Move(EnemyDirection::DownDirection, stepSize);
        }
    }
}

void EnemyController::DamageAll()
{
    if (curent_enemies > 0)
    {
        for (int i = 0; i <= curent_enemies; i++)
        {
            enemies[i].Shoot(i + 1);
        }
    }
}

int EnemyController::CountKilledEnemies()
{
    if (curent_enemies > 0)
    {
        int kill_enemies = 0;
        for (int i=0;i<=curent_enemies;i++)
        {
            if(enemies[i].IsDead())
            {
                kill_enemies++;
            }
        }
        return kill_enemies;
    }
    else
        return 0;
}

bool EnemyController::SpawnEnemy()
{
    if (curent_enemies < maxim_enemies - 1)
    {
        enemies[curent_enemies++].Init(startinLocation, ENEMY_HEALTH);
        return true;
    }
    else
        return false;
}
