#include "../includes/ft_nm.h"

int	parse_elf_64(char *mmap_return, char *file_offset)
{
	int8_t			file_endian = 0;
	_Bool			system_endian = 0;
	_Bool			reverse = 0;
	Elf64_Ehdr		*elf_header;
	Elf64_Shdr		*elf_shdr;
	char			*elf_strtable;
	t_elf_section_part	*elf_sections = NULL;
//	uint64_t		i = 0;
	

	elf_header = (Elf64_Ehdr *)mmap_return;
	ft_printf("ELF ESHOFF = %d\n", elf_header->e_shoff);
	file_endian = get_endian_file(elf_header);
	if (file_endian == FAILURE)
		return(ft_perror("File format not recognized\n", 0));
	system_endian = get_endian_system();
	reverse = need_to_reverse(file_endian, system_endian);
	elf_shdr = (Elf64_Shdr *)(mmap_return + reverse_for_64(elf_header->e_shoff, reverse));
	elf_strtable = mmap_return + reverse_for_64(elf_shdr[reverse_for_64(elf_header->e_shstrndx, reverse)].sh_offset, reverse);
	elf_sections = stock_elf64_sections(reverse_for_64(elf_header->e_shnum, reverse), elf_shdr, elf_strtable, reverse);
	if (elf_sections == MALLOC_FAILED)
		return (ft_perror("Malloc failed to allocate memory\n.", 0));
/*	while (i < reverse_for_64(elf_header->e_shnum, reverse))
	{
		if (reverse_for_64(elf_shdr[i].sh_type, reverse) == SHT_SYMTAB)
		{
			if (stock_elf_sym
		}
	}	
*/	(void)file_offset;
	free(elf_sections);
	return (EXIT_SUCCESS);
}
