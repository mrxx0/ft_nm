#include "../includes/ft_nm.h"

int	parse_elf_32(char *mmap_return, char *file_offset)
{
	(void)file_offset;
	Elf32_Ehdr		*elf_header;
	Elf32_Shdr		*elf_shdr;
	int8_t			file_endian = 0;
	_Bool			system_endian = 0;
	_Bool			reverse = 0;
	char			*elf_strtable;
	t_elf_section_part	*elf_sections = NULL;

	elf_header = (Elf32_Ehdr *)mmap_return;
	if (mmap_return + elf_header->e_shoff > file_offset)
		return (ft_perror("File corrupted\n", 0));	
	file_endian = get_endian_file_32(elf_header);
	if (file_endian == FAILURE)
		return(ft_perror("File format not recognized\n", 0));
	system_endian = get_endian_system();
	reverse = need_to_reverse(file_endian, system_endian);
	elf_shdr = (Elf32_Shdr *)(mmap_return + (uint32_t)reverse_for_32(elf_header->e_shoff, sizeof(elf_header->e_shoff), reverse));
	elf_strtable = mmap_return + reverse_for_32(elf_shdr[(uint16_t)reverse_for_32(elf_header->e_shstrndx,sizeof(elf_header->e_shstrndx), reverse)].sh_offset, sizeof(elf_shdr->sh_offset), reverse);
	elf_sections = stock_elf32_sections((uint16_t)reverse_for_32(elf_header->e_shnum, sizeof(elf_header->e_shnum), reverse), elf_shdr, elf_strtable, reverse);
	if (elf_sections == MALLOC_FAILED)
		return (ft_perror("Malloc failed to allocate memory\n.", 0));
	if (parse_elf32_symbols(elf_header, elf_shdr, elf_sections, reverse) == FALSE)
	{
		if (elf_sections)
			free(elf_sections);
		return (ft_perror("No symbol\n", 0));
	}
	return (EXIT_SUCCESS);
}
