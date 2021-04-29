#include "../includes/ft_nm.h"

int	parse_elf_64(char *mmap_return, char *file_offset)
{
	_Bool		file_endian = 0;
	_Bool		system_endian = 0;
	Elf64_Ehdr	*elf_header;
	
	elf_header = (Elf64_Ehdr *)mmap_return;
	file_endian = get_endian_file(elf_header);
	system_endian = get_endian_system();
	need_to_reverse(file_endian, system_endian);
	(void)mmap_return;
	(void)file_offset;
	return (EXIT_SUCCESS);
}
