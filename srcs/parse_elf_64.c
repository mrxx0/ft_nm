#include "../includes/ft_nm.h"

t_elf_section_part	*get_elf_sections(int e_shnum, Elf64_Shdr *shdr, char *strtable, _Bool reverse)
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
int	parse_elf_64(char *mmap_return, char *file_offset)
{
	_Bool			file_endian = 0;
	_Bool			system_endian = 0;
	_Bool			reverse = 0;
	Elf64_Ehdr		*elf_header;
	Elf64_Shdr		*elf_shdr;
	char			*elf_strtable;
	t_elf_section_part	*elf_sections = NULL;

	elf_header = (Elf64_Ehdr *)mmap_return;
	file_endian = get_endian_file(elf_header);
	system_endian = get_endian_system();
	reverse = need_to_reverse(file_endian, system_endian);
	elf_shdr = (Elf64_Shdr *)(mmap_return + reverse_for_64(elf_header->e_shoff, reverse));
	elf_strtable = mmap_return + reverse_for_64(elf_shdr[reverse_for_64(elf_header->e_shstrndx, reverse)].sh_offset, reverse);
	elf_sections = get_elf_sections(elf_header->e_shnum, elf_shdr, elf_strtable, reverse);
	if (elf_sections == MALLOC_FAILED)
		return (ft_perror("Malloc failed to allocate memory\n.", 0));
		
	(void)file_offset;
	return (EXIT_SUCCESS);
}
