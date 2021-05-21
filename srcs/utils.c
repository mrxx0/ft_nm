#include "../includes/ft_nm.h"

void print_symbol(t_elf_symbol_part *elf_symbols, int index, _Bool class)
{
	int i;

	i = index - 1;
	while (i >= 0)
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
		i--;
	}
}

int count_char_to_skip(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] && !ft_isalnum(str[i]))
	{
		count++;
		i++;
	}
	return (count);
}

int hash (char *str)
{
	int hash;
	int c;

	hash = 0;
	while ((c = *str++))
		hash = c + (hash << 1);
	return (hash);
}

char *transform_str(char *str)
{
	char *ret;

	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]))
			count++;
		i++;
	}
	i = 0;
	ret = ft_strnew(count + 1);
	while (str[i])
	{
		if (ft_isalnum(str[i]))
		{
			ret[j] = str[i];
			j++;
		}
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

int	mystrcmp(char *s1, char *s2, t_elf_symbol_part *syms1, t_elf_symbol_part *syms2)
{
	int res = 0;
	size_t i = 0;
	size_t j = 0;
	_Bool priority = 0;

	(void)syms1;
	(void)syms2;
	
	while (s1[i] == '_' || s1[i] == '.')
		i++;
	while (s2[j] == '_' || s2[j] == '.')
		j++;
	if (j > i && syms2->shndx != SHN_UNDEF)
		priority = 1;
	while (s1[i])
	{
		if (ft_tolower(s1[i]) == ft_tolower(s2[j]))
		{
			i++;
			j++;
		}
		else if ((s1[i] == '_' || s1[i] == '@' || s1[i] == '.')  
			|| (s2[j] == '_' || s2[j] == '@' || s2[j] == '.'))
		{
			if (s1[i] == '_' || s1[i] == '@' || s1[i] == '.')
				i++;
			if (s2[j] == '_' || s2[j] == '@' || s2[j] == '.')
				j++;
		}
		else
			break ;
	}
	res = ft_tolower(s1[i]) - ft_tolower(s2[j]);
	if (res == 0)
	{
		if (priority == 1)
			return (1);
		else
			return (-1);
	}
	return (res);
}

void sort_symbol(t_elf_symbol_part *elf_symbols, int index, _Bool class)
{
	int i = 0;
	int j = 0;
	int swap = 0;
	t_elf_symbol_part tmp;

	while (i + 1 <= index)
	{			
		j = i;
		while (j + 1 <= index)
		{
			swap = mystrcmp(elf_symbols[i].name , elf_symbols[j].name, &elf_symbols[i], &elf_symbols[j]);
			if (swap < 0)
			{
				tmp = elf_symbols[j];
				elf_symbols[j] = elf_symbols[i];
				elf_symbols[i] = tmp;
			}
			else if (swap == 0)
			{
				if (elf_symbols[i].value < elf_symbols[j].value)
				{
					tmp = elf_symbols[j];
					elf_symbols[j] = elf_symbols[i];
					elf_symbols[i] = tmp;
				}
			}
			j++;
		}
		i++;
	}
	// (void)class;
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
