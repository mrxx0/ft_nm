#include "../includes/ft_nm.h"

t_elf_section_part	*stock_elf64_sections(int e_shnum, Elf64_Shdr *shdr, char *strtable, _Bool reverse)
{
	t_elf_section_part *sections = NULL;
	int i;

	sections = malloc(sizeof(t_elf_section_part) * e_shnum);
	if (sections == MALLOC_FAILED)
		return (MALLOC_FAILED);
	else
	{
		i = 0;
		while (i < e_shnum)
		{
			sections[i].name = strtable + reverse_for_64(shdr[i].sh_name, reverse);
			sections[i].type = reverse_for_64(shdr[i].sh_type, reverse);
			sections[i].flag = reverse_for_64(shdr[i].sh_flags, reverse);
			i++;
		}	
		return (sections);
	}
	
}
