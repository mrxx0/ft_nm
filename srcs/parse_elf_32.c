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
	file_endian = get_endian_file_32(elf_header);
	if (file_endian == FAILURE)
		return(ft_perror("File format not recognized\n", 0));
	system_endian = get_endian_system();
	reverse = need_to_reverse(file_endian, system_endian);
	if (reverse_for_32(elf_header->e_ehsize, sizeof(elf_header->e_ehsize), reverse) != EHSIZE_MAX32)
		return (ft_perror("File truncated\n", 0));
	if (mmap_return + reverse_for_32(elf_header->e_shoff, sizeof(elf_header->e_shoff), reverse) > file_offset)
		return (ft_perror("File corrupted\n", 0));
	if (reverse_for_32(elf_header->e_phnum, sizeof(elf_header->e_phnum), reverse) >= PN_XNUM)
		return (ft_perror("Bad value\n", 0));
	if (mmap_return + reverse_for_32(elf_header->e_shoff, sizeof(elf_header->e_shoff), reverse) > file_offset)
		return (ft_perror("File corrupted\n", 0));
	elf_shdr = (Elf32_Shdr *)(mmap_return + (uint32_t)reverse_for_32(elf_header->e_shoff, sizeof(elf_header->e_shoff), reverse));
	if (reverse_for_32(elf_header->e_shstrndx, sizeof(elf_header->e_shstrndx), reverse) >= SHN_LORESERVE )
		return (ft_perror("No symbols\n", 0));
	elf_strtable = mmap_return + reverse_for_32(elf_shdr[(uint16_t)reverse_for_32(elf_header->e_shstrndx,sizeof(elf_header->e_shstrndx), reverse)].sh_offset, sizeof(elf_shdr->sh_offset), reverse);
	if (reverse_for_32(elf_header->e_shnum, sizeof(elf_header->e_shnum), reverse) >= SHN_LORESERVE)
		return (ft_perror("File truncated\n", 0));
	elf_sections = stock_elf32_sections((uint16_t)reverse_for_32(elf_header->e_shnum, sizeof(elf_header->e_shnum), reverse), elf_shdr, elf_strtable, reverse);
	if (elf_sections == MALLOC_FAILED)
		return (ft_perror("Malloc failed to allocate memory\n.", 0));
	// uint16_t i = 0;
	// while (i < (uint16_t)reverse_for_32(elf_header->e_shnum, sizeof(elf_header->e_shnum), reverse) )
	// {
	// 	printf("sections[%d].name = %s\n",i, elf_sections[i].name);
	// 	printf("sections[%d].type = %d\n", i,elf_sections[i].type);
	// 	printf("sections[%d].flag = %lu\n\n",i, elf_sections[i].flag);
	// 	i++;
	// }
	if (parse_elf32_symbols(elf_header, elf_shdr, elf_sections, reverse) == FALSE)
	{
		if (elf_sections)
			free(elf_sections);
		return (ft_perror("No symbol\n", 0));
	}
	free(elf_sections);
	return (EXIT_SUCCESS);
}
