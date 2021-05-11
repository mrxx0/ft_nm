#include "../includes/ft_nm.h"

uint32_t	reverse_for_32(uint32_t offset, _Bool reverse)
{
	if (reverse == TRUE)
	{
		offset = (offset << 16) | (offset >> 16);
		offset = ((offset << 8) & 0xFF00FF00) | ((offset >> 8) & 0xFF00FF);
	}
	return (offset);
}

uint64_t	reverse_for_64(uint64_t offset, _Bool reverse)
{
	if (reverse == TRUE)
	{
		offset = (offset & 0x00000000FFFFFFFF) << 32 | (offset & 0xFFFFFFFF00000000) >> 32;
		offset = (offset & 0x0000FFFF0000FFFF) << 16 | (offset & 0xFFFF0000FFFF0000) >> 16;
		offset = (offset & 0x00FF00FF00FF00FF) << 8  | (offset & 0xFF00FF00FF00FF00) >> 8;	
	}
	return (offset);
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
