#include "bsq.h"

// clear && gcc main.c bsq.c bsq.h && cat bsq_test_maps/map_valid_1.txt | valgrind ./a.out
// clear && gcc main.c bsq.c bsq.h && valgrind ./a.out bsq_test_maps/map_valid_1.txt



int	main(int argc, char ** argv)
{

	//scenarios
	//	1) less than 2 args
	//	2) more than or equal 2 args
	if (argc < 2)
	{
		char *line = NULL;
		size_t len = 0;
		ssize_t nread;

		//if 
		//getline(&line, &len, stdin);
		int		array = 0;
		char	**map = (char **)calloc(array + 1, sizeof(char));

		while ((nread = getline(&line, &len, stdin)) != -1)
		{
			fprintf(stdout, "%s\n", line);
			map[array] = (char *)calloc(len + 1, sizeof(char));
			map[array++] = line;
		}
		map[array] = NULL;
		//file now must be able to read from stdin and check the if map is valid
		// ft_bsq_from_stdin()

		if (line)
			free(line);
	}
	else //(argc >= 2)
		ft_bsq(argv);
	return (0);
}



















