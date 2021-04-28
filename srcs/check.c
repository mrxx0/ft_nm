#include "../includes/ft_nm.h"

int check_file_is_elf(char *mmap_return, char *file_offset, char *file_name)
{
	(void) file_name;
	if (mmap_return > file_offset)
		return (ft_perror("File is corrupted\n", 0));
	if ((unsigned char)mmap_return[EI_MAG0] == 0x7f &&
		(unsigned char)mmap_return[EI_MAG1] == 'E' &&
		(unsigned char)mmap_return[EI_MAG2] == 'L' &&
		(unsigned char)mmap_return[EI_MAG3] == 'F')
	{
		if ((unsigned char)mmap_return[EI_CLASS] == ELFCLASS64)
		{
			parse_elf_64(mmap_return, file_offset);
		}
		if ((unsigned char)mmap_return[EI_CLASS] == ELFCLASS32)
		{
			parse_elf_32(mmap_return, file_offset);
		}
		ft_printf("File is ELF format !\n");
		return (EXIT_SUCCESS);
	}
	else
		return (ft_perror("File is not ELF format\n", 0));


(void)file_name;
	return (EXIT_SUCCESS);
}
