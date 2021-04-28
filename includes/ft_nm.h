#ifndef FT_NM_H
#define FT_NM_H

#include "../libft/includes/libft.h"
#include <string.h>
#include <elf.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define FAILURE -1
#define SUCCESS 1
typedef struct	s_section_elf
{
	char 		*name;
	uint32_t	type;
	uint32_t	flag;
}		t_section_elf;

typedef struct	s_symbol_elf
{
	char 		*name;
	uint8_t		type;
//	uint8_t		bind;
//	uint8_t		shndx;
//	uint64_t	value;
}		t_symbol_elf;

int	ft_perror(char *error_message, int fd);
int	open_file(char *file_name, int *fd, char **mmap_return, struct stat *stat);
int	check_file_is_elf(char *mmap_return, char *file_offset, char *file_name);

#endif 
