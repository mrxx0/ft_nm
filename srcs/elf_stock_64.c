#include "../includes/ft_nm.h"

int			stock_elf64_symbols(Elf64_Sym *elf_sym, Elf64_Shdr *elf_shdr, Elf64_Ehdr *elf_header, int i, t_elf_section_part *elf_sections, _Bool reverse)
{
	t_elf_symbol_part *elf_symbols = NULL;
	uint64_t			symctr = 0;
	uint64_t			j = 0;
	int					k = 0;
	char				*elf_symstrtable;

	symctr = reverse_for_64(elf_shdr[i].sh_size, sizeof(elf_shdr[i].sh_size), reverse) / reverse_for_64(elf_shdr[i].sh_entsize, sizeof(elf_shdr[i].sh_entsize), reverse);
	elf_symstrtable = (char *)((char *)elf_header + reverse_for_64(elf_shdr[reverse_for_64(elf_shdr[i].sh_link, sizeof(elf_shdr[i].sh_link), reverse)].sh_offset, sizeof(elf_shdr->sh_offset), reverse));
	elf_symbols = malloc(sizeof(t_elf_symbol_part) * symctr);
	if (elf_symbols == MALLOC_FAILED)
		return (ft_perror("Malloc failed to allocate memory\n.", 0));
	while (j < symctr)
	{
		if (elf_sym[j].st_name != 0 && ELF64_ST_TYPE((unsigned char)reverse_for_64(elf_sym[j].st_info, sizeof(elf_sym[i].st_info), reverse)) != STT_FILE
			&& ELF64_ST_TYPE((unsigned char)reverse_for_64(elf_sym[j].st_info, sizeof(elf_sym[j].st_info), reverse)) != STT_SECTION)
			{
				elf_symbols[k].value = reverse_for_64(elf_sym[j].st_value, sizeof(elf_sym[j].st_value), reverse);
				
				elf_symbols[k].type = (uint8_t)ELF64_ST_TYPE(reverse_for_64(elf_sym[j].st_info, sizeof(elf_sym[j].st_info), reverse));
				elf_symbols[k].bind = (uint8_t)ELF64_ST_BIND(reverse_for_64(elf_sym[j].st_info, sizeof(elf_sym[j].st_info), reverse));
				elf_symbols[k].shndx = (uint16_t)reverse_for_64(elf_sym[j].st_shndx, sizeof(elf_sym[j].st_shndx), reverse);
				elf_symbols[k].name = elf_symstrtable + reverse_for_64(elf_sym[j].st_name, sizeof(elf_sym[j].st_name), reverse);
				elf_symbols[k].sym_type = elf_symbol_type(elf_symbols[k], elf_sections, (int)reverse_for_64(elf_header->e_shnum,sizeof(elf_header->e_shnum), reverse));
				if (elf_symbols[k].bind == STB_LOCAL && elf_symbols[k].sym_type != '?')
					elf_symbols[k].sym_type += 32;
				k++;
			}
			j++;
	}
	sort_symbol(elf_symbols, k, 1);
	free(elf_symbols);
	return (TRUE);
}

_Bool			parse_elf64_symbols(Elf64_Ehdr *elf_header, Elf64_Shdr *elf_shdr, t_elf_section_part *elf_sections, _Bool reverse)
{
	uint64_t i = 0;
	_Bool 		is_symbol = FALSE;

	while (i < reverse_for_64(elf_header->e_shnum, sizeof(elf_header->e_shnum), reverse))
	{
		if ((uint32_t)reverse_for_64(elf_shdr[i].sh_type, sizeof(elf_shdr[i].sh_type), reverse) == SHT_SYMTAB)
		{
			stock_elf64_symbols((Elf64_Sym *)((char *)elf_header + reverse_for_64(elf_shdr[i].sh_offset, sizeof(elf_shdr[i].sh_offset), reverse)), elf_shdr, elf_header, i, elf_sections, reverse);
			is_symbol = TRUE;
		}
		i++;
	}
	if (is_symbol == FALSE)
		return (FALSE);
	
	return (TRUE);
}

t_elf_section_part	*stock_elf64_sections(uint16_t e_shnum, Elf64_Shdr *shdr, char *strtable, _Bool reverse)
{
	t_elf_section_part *sections = NULL;
	uint16_t i;

	sections = malloc(sizeof(t_elf_section_part) * e_shnum);
	if (sections == MALLOC_FAILED)
		return (MALLOC_FAILED);
	else
	{
		i = 0;
		while (i < e_shnum)
		{
			sections[i].name = strtable + reverse_for_64(shdr[i].sh_name, sizeof(shdr[i].sh_name), reverse);
			sections[i].type = (uint32_t)reverse_for_64(shdr[i].sh_type, sizeof(shdr[i].sh_type), reverse);
			sections[i].flag = reverse_for_64(shdr[i].sh_flags,sizeof(shdr[i].sh_flags), reverse);
			i++;
		}	
		return (sections);
	}
	
}
