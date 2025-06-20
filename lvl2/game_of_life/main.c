#include "life.h"


int	main(int argc, char **argv)
{
	printf("Creating my first game of life!!\n");
	if (argc == 4)
		game_of_life_start(argv);//convert the char into size_t
	else
		printf("[ERROR] Not enough arguements\n");
	return (0);
}