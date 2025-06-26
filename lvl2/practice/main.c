#include "life.h"

//clear && gcc main.c life.c life.h && valgrind ./a.out 3 3 0

int     main(int argc, char **argv)
{
    if (argc != 4)
        return (1);
    
   int  width = atoi(argv[1]);
   int  height = atoi(argv[2]);
   int  iteration = atoi(argv[3]);

   game_of_life_start(width, height, iteration);

   return (0);
}