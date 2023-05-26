#include "dogmove.h"

void init_dogmove(Dogmove* dogmove)
{
    dogmove->isDogInHouse = false;
}

void update_dogmove(Dogmove* dogmove, bool value)
{
    dogmove->isDogInHouse = value;
}
