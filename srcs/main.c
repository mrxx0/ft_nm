#include "../includes/ft_nm.h"

int main(int argc, char **argv)
{	
	if (argc < 2)
		return (ft_perror("Failure arguments\n", 0)); 	// Proper error format.
	int i 	= 		1;
	int fd 	= 		0;
	char *mmap_return = 	NULL;
	struct stat stat;
	while (i < argc)
	{	
		//output format
		if (open_file(argv[i], &fd, &mmap_return, &stat) == FAILURE)
			return (EXIT_FAILURE);
		if ((check_file_is_elf(mmap_return, mmap_return + stat.st_size, argv[i]) == FAILURE))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
