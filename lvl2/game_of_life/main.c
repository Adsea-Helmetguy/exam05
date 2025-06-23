#include "life.h"

//clear && gcc main.c life.c life.h && echo 'sdxddssaaww' | valgrind --leak-check=full --show-leak-kinds=all ./a.out 5 5 0 && rm ./a.out life.h.gch

//clear && gcc main.c life.c life.h && echo 'sdxssdswdxdddxsaddawxwdxwaa' | valgrind --leak-checkfull --show-leak-kinds=all ./a.out 10 6 0 && rm ./a.out life.h.gch

//clear && gcc main.c life.c life.h && echo 'dxss' | valgrind --leak-check=full --show-leak-kinds=all ./a.out 3 3 1 && rm ./a.out life.h.gch


int	main(int argc, char **argv)
{
	printf("Creating my first game of life!!\n");
	if (argc == 4)
		game_of_life_start(argv);//convert the char into size_t
	else
		printf("[ERROR] Not enough arguements\n");
	return (0);
}