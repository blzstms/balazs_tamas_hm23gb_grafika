#include "brick.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	Brick brick;
	double volume;
	double surface;

	set_brick_size(&brick, 5, 10, 8);
	volume = calc_brick_volume(&brick);
	surface = calc_brick_surface(&brick);


	printf("Brick volume: %lf\n", volume);
	printf("Brick surface: %lf\n", surface);

	square_test(&brick);



	return 0;
}
