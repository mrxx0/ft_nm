#include "../includes/ft_nm.h"

int validate_elf_type(char *mmap_return, char *file_offset)
{
	if (mmap_return > file_offset)
		return (0);
	if (ft_strncmp(mmap_return, ELFMAG, 4) == 0)
	{
		if ((unsigned char)mmap_return[EI_CLASS] == ELFCLASS64)
			return (1);
		if ((unsigned char)mmap_return[EI_CLASS] == ELFCLASS32)
			return (1);
		return (0);
	}
	else if (ft_strncmp(mmap_return, ARMAG, SARMAG) == 0)
		return (1);
	else
		return (0);
}

int check_file_is_elf(char *mmap_return, char *file_offset, char *file_name)
{
	if (mmap_return > file_offset)
		return (ft_perror("File is corrupted\n", 0));
	if (ft_strncmp(mmap_return, ELFMAG, 4) == 0)
	{
		if ((unsigned char)mmap_return[EI_CLASS] == ELFCLASS64)
		{
			if (parse_elf_64(mmap_return, file_offset) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if ((unsigned char)mmap_return[EI_CLASS] == ELFCLASS32)
		{
			if (parse_elf_32(mmap_return, file_offset) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(mmap_return, ARMAG, SARMAG) == 0)
	{
			if (parse_ar(mmap_return, file_offset, file_name) == EXIT_FAILURE)
				return (EXIT_FAILURE);
	}
	else
		return (ft_perror("File format not recognized\n", 0));

	return (EXIT_SUCCESS);
}
