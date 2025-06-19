#include "life.h"

int	main(int argc, char **argv)
{
	printf("Creating my first game of life->");
	if (argc = 4)
	{
		if (!arguement_are_num_checker(argv))
		{
			printf("These are not numbers")
			return ;
		}
		game_of_life_start(argv);//convert the char into size_t
	}
	else
		printf("Not enough arguements");
}