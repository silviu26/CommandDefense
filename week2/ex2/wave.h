#pragma once

class wave
{
  private:
    mutable char* wave_name;
    mutable int nr_enemis;
    mutable int health_enemy;
    float money_enemis;
    

  public:
    friend int compare_money(wave,  wave);
    friend int compare_number(wave, wave);
    void init(char* nume, int nrenemies, int health, float money);
    void set_name(char* nume);
    void set_nr_enemies(int nr);
    void set_health(int nr);
    void set_money(float nr);
};