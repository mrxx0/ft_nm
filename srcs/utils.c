#include "../includes/ft_nm.h"

void print_symbol(t_elf_symbol_part *elf_symbols, int index, _Bool class)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (class == 1)
		{
			if (elf_symbols[i].shndx == SHN_UNDEF)
				printf("%16c", ' ');
			else
			printf("%016lx", elf_symbols[i].value);
			printf(" %c", elf_symbols[i].sym_type);
			printf(" %s\n", elf_symbols[i].name);
		}
		else
		{
			if (elf_symbols[i].shndx == SHN_UNDEF)
			printf("%8c", ' ');
			else
			printf("%08lx", elf_symbols[i].value);
			printf(" %c", elf_symbols[i].sym_type);
			printf(" %s\n", elf_symbols[i].name);
		}
		i++;
	}
}

int	mystrcmp(char *s1, char *s2)
{
	int res = 0;

	while (*s1 == '_' || *s1 == '.' || *s1 == '@')
		s1++;
	while (*s2 == '_' || *s2 == '.' || *s2 == '@')
		s2++;
	if (*s1 == *s2)
		return (0);
	while (res == 0)
	{
		if (*s1 == '\0')
			break;
		while (*s1 == '_' || *s1 == '@' || *s1 == '.')
			s1++;
		while (*s2 == '_' || *s2 == '@' || *s2 == '.')
			s2++;
		res = ft_tolower(*s1) - ft_tolower(*s2);
		s1++;
		s2++;
	}
	return (res);
}

void sort_symbol(t_elf_symbol_part *elf_symbols, int index, _Bool class)
{
	int i = 0;
	int j = 0;
	t_elf_symbol_part tmp;

	while (i + 1 < index)
	{
		while (j < index)
		{
			if (mystrcmp(elf_symbols[i].name , elf_symbols[j].name ) < 0)
			{
				tmp = elf_symbols[i];
				elf_symbols[i] = elf_symbols[j];
				elf_symbols[j] = tmp;
			}
			j++;
		}
		i++;
		j = 0;
	}
	print_symbol(elf_symbols, index, class);
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
		return (EXIT_FAILURE);
		// return (ft_perror("Mmap error\n", *fd));	
	return(EXIT_SUCCESS);
}

int	ft_perror(char *error_message, int fd)
{
	write(2, error_message, ft_strlen(error_message));
	if (fd)
		close(fd);
	return (EXIT_FAILURE);
}
