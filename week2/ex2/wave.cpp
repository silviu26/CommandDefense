#include "wave.h"

void wave::init(char* nume, int nrenemies, int health, float money)
{
    if (!(nume == nullptr || nrenemies <= 0 || health <= 0 || money <= 0))
    {
        wave_name    = nume;
        nr_enemis    = nrenemies;
        health_enemy = health;
        money_enemis = money;
    }
}

void wave::set_name(char* nume)
{
    if (nume != nullptr)
        wave_name = nume;
}

void wave::set_nr_enemies(int nr)
{
    if (nr > 0)
        nr_enemis = nr;
}

void wave::set_health(int nr)
{
    if (nr > 0)
        health_enemy = nr;
}

void wave::set_money(float nr)
{
    if (nr > 0)
        money_enemis = nr;
}