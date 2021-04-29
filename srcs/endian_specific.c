#include "../includes/ft_nm.h"

_Bool   need_to_reverse(_Bool file_endian, _Bool system_endian)
{
	if (file_endian != system_endian)
		return (TRUE);
	else
		return (FALSE);
}

_Bool   get_endian_file(Elf64_Ehdr *elf_header)
{
	if (elf_header->e_ident[EI_DATA] == ELFDATA2LSB)
		return (LITTLE);
	else
		return (BIG);
}

_Bool   get_endian_system(void)
{
	uint8_t x = 1;
	char *y = (char*)&x;

	if (*y == LITTLE)
		return (LITTLE);
	else
		return (BIG);
}
