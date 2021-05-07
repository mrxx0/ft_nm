#include "../includes/ft_nm.h"

int check_file_is_elf(char *mmap_return, char *file_offset, char *file_name)
{
	if (mmap_return > file_offset)
		return (ft_perror("File is corrupted\n", 0));
	/*if ((unsigned char)mmap_return[EI_MAG0] == 0x7f &&
		(unsigned char)mmap_return[EI_MAG1] == 'E' &&
		(unsigned char)mmap_return[EI_MAG2] == 'L' &&
		(unsigned char)mmap_return[EI_MAG3] == 'F')*/
	if (ft_strncmp(mmap_return, ELFMAG, 4) == 0)
	{

		if ((unsigned char)mmap_return[EI_CLASS] == ELFCLASS64)
		{
			if (parse_elf_64(mmap_return, file_offset) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		if ((unsigned char)mmap_return[EI_CLASS] == ELFCLASS32)
		{
			parse_elf_32(mmap_return, file_offset);
		}
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(mmap_return, ARMAG, SARMAG) == 0)
	{
		ft_printf("This is an ar .a file !\n");
			if (parse_ar(mmap_return, file_offset) == EXIT_FAILURE)
				return (EXIT_FAILURE);
	}
	else
		return (ft_perror("File format not recognized\n", 0));

(void)file_name;
	return (EXIT_SUCCESS);
}
