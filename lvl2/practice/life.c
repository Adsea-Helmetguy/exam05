#include "life.h"

void	print_board(char **board)
{
	int	row = 0;
	int	col = 0;

	if (!board)
		return ;

	while (board[row])
	{
		col = 0;
		while (board[row][col])
		{
			putchar(board[row][col]);
			col++;
		}
		putchar('\n');
		row++;
	}
		
}

void	free_board(char **board, int height)
{
	int		row = 0;

	while (row < height)
		free(board[row++]);
	free(board);
}

char    **board_creation(int width, int height)
{
	int		row = 0;
	int		col = 0;
	char	**empty_board;

	empty_board = (char **)calloc(height + 1, sizeof(char *));
	while (row < height)
	{
		empty_board[row] = (char *)calloc(width + 1, sizeof(char));
		col = 0;
		while (col < width)
		{
			empty_board[row][col] = ' ';
			col++;
		}
		empty_board[row][col] = '\0';
		row++;
	}
	empty_board[row] = NULL;
	return (empty_board);
}

char	**add_living_cells(int width, int height)
{
	char	**new_board;
	char	buf;
	int		index = 0;
	int		array = 0;
	bool	start_drawing = false;

	new_board = board_creation(width, height);
	while (read(0, &buf, 1) > 0)
	{
		printf("buf = %c\n", buf);
		if (buf == 'w' && array > 0)
			array--;
		else if (buf == 'a' && index > 0)
			index--;
		else if (buf == 's' && (array + 1) < height)
			array++;
		else if (buf == 'd' && (index + 1) < width)
			index++;
		else if (buf == 'x')
			start_drawing = !start_drawing;
		
		if (start_drawing == true)
			new_board[array][index] = '0';

	}
	return (new_board);
}

void    game_of_life_start(int width, int height, int iteration)
{
	char	**new_board;

	new_board = add_living_cells(width, height);

	print_board(new_board);
	free_board(new_board, height);
}