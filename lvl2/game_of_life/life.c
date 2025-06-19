#include "life.h"

//Create a function to create a board

//Check the arguments and if its correct, store them as size_t value
//1.1) check the iteration, if its >= to the value, stop the game.

//2) create a function, clone the board only by its width and height. Make it empty board.

// --Working on getting new cells--
//3) figure out the new location of the new generation of cells, store their locations.
//4) figure out the next iteration where the cells are gonna be ded. Store their locations.

//5) free the old board and replace it with the new one
//Repeat




bool	arguement_are_num_checker(char **argv)
{
    int	array;
	array = 1;
	while (array <= 3 && argv[array])
	{
		atoi(argv[1])
	}
	return (true);
}