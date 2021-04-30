#include "../includes/ft_nm.h"

int			stock_elf64_symbols(Elf64_Sym *elf_sym, Elf64_Shdr *elf_shdr, Elf64_Ehdr *elf_header, int i, t_elf_section_part *elf_sections, _Bool reverse)
{
	t_elf_symbol_part *elf_symbols = NULL;
	int					symctr = 0;
	int					j = 0;
	int					k = 0;
	char				*elf_symstrtable;
	(void) elf_sections;

	symctr = reverse_for_64(elf_shdr[i].sh_size, reverse) / reverse_for_64(elf_shdr[i].sh_entsize, reverse);
	elf_symstrtable = (char *)((char *)elf_header + reverse_for_64(elf_shdr[reverse_for_64(elf_shdr[i].sh_link, reverse)].sh_offset, reverse));
	elf_symbols = malloc(sizeof(t_elf_symbol_part) * symctr);
	if (elf_symbols == MALLOC_FAILED)
		return (ft_perror("Malloc failed to allocate memory\n.", 0));
	while (j < symctr)
	{
		if (elf_sym[j].st_name != 0 && ELF64_ST_TYPE(reverse_for_64(elf_sym[j].st_info, reverse)) != STT_FILE
			&& ELF64_ST_TYPE(reverse_for_64(elf_sym[j].st_info, reverse)) != STT_SECTION)
			{
				elf_symbols[k].value = reverse_for_64(elf_sym[j].st_value, reverse);
				ft_printf("%016x\t", elf_symbols[k].value);

				elf_symbols[k].type = ELF64_ST_TYPE(reverse_for_64(elf_sym[j].st_info, reverse));
				ft_printf("%u\t", elf_symbols[k].type);

				elf_symbols[k].bind = ELF64_ST_BIND(reverse_for_64(elf_sym[j].st_info, reverse));
				ft_printf("%u\t", elf_symbols[k].bind);

				elf_symbols[k].shndx = reverse_for_64(elf_sym[j].st_shndx, reverse);
				ft_printf("%u\t", elf_symbols[k].shndx);

				elf_symbols[k].name = elf_symstrtable + reverse_for_64(elf_sym[j].st_name, reverse);
				ft_printf("%s\n", elf_symbols[k].name);
				k++;
			}
			j++;
	}
	
	return (TRUE);
}


_Bool			parse_elf64_symbols(Elf64_Ehdr *elf_header, Elf64_Shdr *elf_shdr, t_elf_section_part *elf_sections, _Bool reverse)
{
	uint64_t i = 0;
	_Bool 		is_symbol = FALSE;

	while (i < reverse_for_64(elf_header->e_shnum, reverse))
	{
		if (reverse_for_64(elf_shdr[i].sh_type, reverse) == SHT_SYMTAB)
		{
			stock_elf64_symbols((Elf64_Sym *)((char *)elf_header + reverse_for_64(elf_shdr[i].sh_offset, reverse)), elf_shdr, elf_header, i, elf_sections, reverse);
			is_symbol = TRUE;
		}
		
		i++;
	}
	if (is_symbol == FALSE)
		return (FALSE);
	
	return (TRUE);
}

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
