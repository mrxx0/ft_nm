#include "../includes/ft_nm.h"

_Bool	need_to_reverse(_Bool file_endian, _Bool system_endian)
{
	if (file_endian != system_endian)
		return (TRUE);
	else
		return (FALSE);
}

_Bool	get_endian_file(Elf64_Ehdr *elf_header)
{
	if (elf_header->e_ident[EI_DATA] == ELFDATA2LSB)
		return (LITTLE);
	else
		return (BIG);
}

_Bool	get_endian_system(void)
{
	uint8_t x = 1;
	char *y = (char*)&x;

	if (*y == LITTLE)
		return (LITTLE);
	else
		return (BIG);
}

int	open_file(char *file_name, int *fd, char **mmap_return,  struct stat *stat)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
	{
		if (errno == EACCES && *fd == -1)
			return(ft_perror("Permission denied.\n", *fd));
		else if (*fd == -1)
			return(ft_perror("No such file or directory.\n", *fd));
	}
	if (fstat(*fd, stat) == -1)
		return (ft_perror("Not a valid open file descriptor.\n", *fd));
	if (S_ISDIR(stat->st_mode))
		return (ft_perror("Is a directory.\n", *fd));	
	if ((*mmap_return = mmap(0, stat->st_size, PROT_READ, MAP_PRIVATE, *fd, 0)) == MAP_FAILED)
		return (ft_perror("Mmap error\n", *fd));	
	return(EXIT_SUCCESS);
}

int	ft_perror(char *error_message, int fd)
{
	write(2, error_message, ft_strlen(error_message));
	if (fd)
		close(fd);
	return (EXIT_FAILURE);
}
