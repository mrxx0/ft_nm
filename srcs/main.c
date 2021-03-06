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
		if (open_file(argv[i], &fd, &mmap_return, &stat) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if ((check_file_is_elf(mmap_return, mmap_return + stat.st_size, argv[i]) == EXIT_FAILURE))
			return (EXIT_FAILURE);
		if (munmap(mmap_return, stat.st_size) == FAILURE)
			return (ft_perror("Can't munmap mmap_return\n", fd));
		else
			close(fd);
		i++;
	}
	return (EXIT_SUCCESS);
}
