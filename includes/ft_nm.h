#ifndef FT_NM_H
#define FT_NM_H

#include "../libft/includes/libft.h"
#include <string.h>
#include <elf.h>
#include <ar.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define FAILURE -1

#define TRUE 1
#define FALSE 0

#define BIG 0
#define LITTLE 1

#define MALLOC_FAILED NULL

typedef struct	s_elf_section_part
{
	char 		*name;
	uint32_t	type;
	uint64_t	flag;
}		t_elf_section_part;

typedef struct	s_elf_symbol_part
{
	char 		*name;
	char		sym_type;
	uint8_t		type;
	uint8_t		bind;
	uint16_t	shndx;
	uint64_t	value;
}		t_elf_symbol_part;

int				ft_perror(char *error_message, int fd);
int				open_file(char *file_name, int *fd, char **mmap_return, struct stat *stat);
int				check_file_is_elf(char *mmap_return, char *file_offset, char *file_name);
int				parse_elf_64(char *mmap_return, char *file_offset);
int				parse_elf_32(char *mmap_return, char *file_offset);
int				parse_ar(char *mmap_return, char *file_offset, char *file_name);
_Bool				get_endian_system();
int8_t				get_endian_file_64(Elf64_Ehdr *elf_header);
int8_t				get_endian_file_32(Elf32_Ehdr *elf_header);
_Bool				need_to_reverse(_Bool file_endian, _Bool system_endian);
uint64_t			reverse_for_64(uint64_t offset, _Bool reverse);
uint32_t			reverse_for_32(uint32_t x, size_t size, _Bool reverse);
t_elf_section_part		*stock_elf64_sections(uint16_t e_shnum, Elf64_Shdr *shdr, char *strtable, _Bool reverse);
t_elf_section_part		*stock_elf32_sections(uint16_t e_shnum, Elf32_Shdr *shdr, char *strtable, _Bool reverse);
_Bool				parse_elf64_symbols(Elf64_Ehdr *elf_header, Elf64_Shdr *elf_shdr, t_elf_section_part *elf_sections, _Bool reverse);
_Bool				parse_elf32_symbols(Elf32_Ehdr *elf_header, Elf32_Shdr *elf_shdr, t_elf_section_part *elf_sections, _Bool reverse);
char    			elf_symbol_type_64(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, Elf64_Sym *elf_sym, t_elf_section_part *elf_sections);
char    			elf_symbol_type_32(t_elf_symbol_part *elf_symbols, Elf32_Shdr *elf_shdr, Elf32_Sym *elf_sym, t_elf_section_part *elf_sections);

int 				validate_elf_type(char *mmap_return, char *file_offset);


#endif 
