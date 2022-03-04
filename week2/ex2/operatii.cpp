#include "operatii.h"

int compare_number(wave w1, wave w2)
{
    if (w1.nr_enemis < w2.nr_enemis)
        return -1;
    if (w1.nr_enemis > w2.nr_enemis)
        return 1;
    return 0;
}

int compare_money(wave w1, wave w2)
{
    if (w1.money_enemis < w2.money_enemis)
        return -1;
    if (w1.money_enemis > w2.money_enemis)
        return 1;
    return 0;
}
