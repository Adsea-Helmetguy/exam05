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


/*
pen no move outside board and stays still if a command ask for it.
pen do nothing in case of invalid command.
*/
void free_board(char **board, int height)
{
    for (int i = 0; i < height; i++)
        free(board[i]);
    free(board);
}

char**	living_cells(char **new_board)
{
	int	index;
	int	array;

	index = 0;
	array = 0;
	
	new_board[array][index]
	
}

char**	board_creation(int width, int height)
{
	char	**new_board;
	int		index;
	int		array;

	new_board = (char **)calloc(height, sizeof(char *));
    if (!new_board)
        return NULL;

	array = 0;
	while (array < height)
	{
		new_board[array] = (char *)calloc(width + 1, sizeof(char)); // +1 for '\0' if needed
		if (!new_board[array])
		{
			// Cleanup if allocation fails
			while (--array >= 0)
				free(new_board[array]);
			free(new_board);
			return (NULL);
		}
		index = 0;
		while (index < width)
		{
			new_board[array][index] = 'x';//change to space ' ' ltr;
			index++;
		}
		printf("[Test] %s\n", new_board[array]);
		array++;
    }
	living_cells(new_board);
	return (new_board);
	//or assign new function to find living cells
}

void	game_of_life_start(char	**argv)
{
	int		width;
	int		height;
	int		iterations;
	char	**board;

	width = atoi(argv[1]);
	height = atoi(argv[2]);
	iterations = atoi(argv[3]);

	board = board_creation(width, height);
	if (!board)
		return ;

	// at the end of game
	free_board(board, height);
}