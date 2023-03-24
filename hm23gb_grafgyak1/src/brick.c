#include "brick.h"

#include <math.h>

void set_brick_size(Brick* brick, double a, double b, double c)
{
    brick -> a = a;
    brick -> b = b;
    brick -> c = c;
}

double calc_brick_volume(const Brick* brick)
{
	double volume =   brick ->a * brick-> b * brick-> c;
	return volume;
}

double calc_brick_surface(const Brick* brick)
{
	double surface =  2*(brick -> a * brick -> b + brick -> a * brick -> c + brick -> b * brick -> c);
	return surface;
}
void square_test(const Brick* brick)
{
    if(brick -> a == brick ->b ){
        printf("The brick has got a square side\n");
    }
    else if
        (brick-> b == brick->c) {
            printf("The brick has got a square side\n");
    }
    else if
        (brick-> a == brick-> c){
            printf("The brick has got a square side\n");
    } else {
        printf("The brick hasn't got a square side\n");
    }

}
