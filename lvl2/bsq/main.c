#include "bsq.h"

/*
	map contains 3 things
	1) 'empty' char
	2) lines
	3) 'obstacle' char

	replace 'empty' char with 'full' char
*/
// gcc 
int	main(int argc, char ** argv)
{
	//	Should there be no passed arguments, your program must be able to read on the standard input.
	//	"your program must be able to read on the standard input."
	if (argc == 1)
		return (1);
	/*
		FILE *file = fopen("/dev/stdin", "r");
		if (!file)
		{
			write(2, "map error\n", 10);
			return 1;
		}
	*/
	
	// Loop through each file passed in argv[1] to argv[argc - 1]
	// Read the map from the file
	ft_bsq(argv);
	return (0);
}
