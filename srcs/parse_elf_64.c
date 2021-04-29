#include "../includes/ft_nm.h"

int	parse_elf_64(char *mmap_return, char *file_offset)
{
	_Bool		file_endian = 0;
	_Bool		system_endian = 0;
	_Bool		reverse_endian = 0;
	Elf64_Ehdr	*elf_header;
	Elf64_Shdr	*elf_shdr;
	char		*elf_strtable;

	elf_header = (Elf64_Ehdr *)mmap_return;
	file_endian = get_endian_file(elf_header);
	system_endian = get_endian_system();
	reverse_endian = need_to_reverse(file_endian, system_endian);
	if (reverse_endian == TRUE)
	{
		elf_shdr = (Elf64_Shdr *)(mmap_return + reverse_for_64(elf_header->e_shoff));
		elf_strtable = mmap_return + reverse_for_64(elf_shdr[reverse_for_64(elf_header->e_shstrndx)].sh_offset);
	}
	else
	{
		elf_shdr = (Elf64_Shdr *)(mmap_return + elf_header->e_shoff);
		elf_strtable = mmap_return + (elf_shdr[elf_header->e_shstrndx].sh_offset);
	}
		
	(void)file_offset;
	return (EXIT_SUCCESS);
}
