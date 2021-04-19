#include "../includes/ft_nm.h"
#include <string.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	if (argc > 2 || argc == 1)
		return (-1);
	int fd;
	//struct stat stat = {0};
	struct stat stat = {0};
	char *mmap_return;
	fd = -1;

	fd = open(argv[1], O_RDONLY);
	mmap_return = NULL;
	if (fd < 0)
	{
		ft_printf("%s", "ERROR : fd is negative");
		if (fd != -1)
			close(fd);
		return (-1);
	}
	
	if (fstat(fd, &stat) != 0)
	{
		ft_printf("%s", "ERROR : return of stat is not OK");
		return (-1);
	}

	ft_printf("%s is open and it's size is : %d bytes\n", argv[1], stat.st_size);
	mmap_return = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (mmap_return == MAP_FAILED)
	{
		ft_printf("%s", "ERROR : MAP_FAILED");
		return (-1);
	}
	
	if (fd != -1)
		close(fd);
	if (mmap_return != MAP_FAILED)
	{
		munmap((void*)mmap_return, stat.st_size);
	}
	return (1);
}
