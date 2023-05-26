#ifndef DOGMOVE_H_INCLUDED
#define DOGMOVE_H_INCLUDED

#include <stdbool.h>

typedef struct Dogmove
{

bool isDogInHouse;

}Dogmove;

void init_dogmove(Dogmove* dogmove);

void update_dogmove(Dogmove* dogmove, bool value);

#endif // DOGMOVE_H_INCLUDED
