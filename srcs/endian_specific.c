#include "../includes/ft_nm.h"

uint32_t	reverse_for_32(uint32_t x, size_t size, _Bool reverse)
{
	int				i = 0;
	uint32_t		y = 0;
	unsigned char	*ptr_x, *ptr_y;
	if (!reverse)
		return (x);
	ptr_x = (unsigned char *)&x;
	ptr_y = (unsigned char *)&y;
	while (--size)
		ptr_y[i++] = ptr_x[size];
	ptr_y[i++] = ptr_x[size];
	return (y);
}

uint64_t	reverse_for_64(uint64_t x, size_t size, _Bool reverse)
{
	int				i = 0;
	uint64_t		y = 0;
	unsigned char	*ptr_x, *ptr_y;
	if (!reverse)
		return (x);
	ptr_x = (unsigned char *)&x;
	ptr_y = (unsigned char *)&y;
	while (--size)
		ptr_y[i++] = ptr_x[size];
	ptr_y[i++] = ptr_x[size];
	return (y);
}

_Bool   	need_to_reverse(_Bool file_endian, _Bool system_endian)
{
	if (file_endian != system_endian)
		return (TRUE);
	else
		return (FALSE);
}

int8_t   	get_endian_file_32(Elf32_Ehdr *elf_header)
{
	if (elf_header->e_ident[EI_DATA] == ELFDATANONE)
		return (FAILURE);
	else if (elf_header->e_ident[EI_DATA] == ELFDATA2LSB)
		return (LITTLE);
	else if (elf_header->e_ident[EI_DATA] == ELFDATA2MSB)
		return (BIG);
	else
		return (FAILURE);
}

int8_t   	get_endian_file_64(Elf64_Ehdr *elf_header)
{
	if (elf_header->e_ident[EI_DATA] == ELFDATANONE)
		return (FAILURE);
	else if (elf_header->e_ident[EI_DATA] == ELFDATA2LSB)
		return (LITTLE);
	else if (elf_header->e_ident[EI_DATA] == ELFDATA2MSB)
		return (BIG);
	else
		return (FAILURE);
}

_Bool   	get_endian_system(void)
{
	uint8_t x = 1;
	char *y = (char*)&x;

	if (*y == LITTLE)
		return (LITTLE);
	else
		return (BIG);
}
