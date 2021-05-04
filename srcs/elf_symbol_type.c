#include "../includes/ft_nm.h"
char elf_type_initarray(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr)
{
	if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC + SHF_WRITE)
	{
		return (elf_symbols->bind == STB_LOCAL ? 't' : 'T');
		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('t');
		// else
		// 	return('T');
	}
	else
		return('?');
}
char elf_type_dynamic(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr)
{
	if (elf_shdr[elf_symbols->shndx].sh_flags == (SHF_ALLOC + SHF_WRITE))
	{	
		return (elf_symbols->bind == STB_LOCAL ? 'd' : 'D');
		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('d');
		// else
		// 	return('D');
	}
	else if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC)
	{
		return (elf_symbols->bind == STB_LOCAL ? 'r' : 'R');
		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('r');
		// else
		// 	return('R');
	}
	else
		return('?');
}
char 	elf_type_progbits(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, t_elf_section_part *elf_sections)
{
	if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_EXECINSTR)
	{
		if (elf_symbols->bind == STB_WEAK)
		{
			return (elf_symbols->shndx == SHN_UNDEF ? 'w' : 'W');
			// if (elf_symbols->shndx == SHN_UNDEF)
			// 	elf_symbols->sym_type = 'w';
			// return('W');
		}
		return (elf_symbols->bind == STB_LOCAL ? 't' : 'T');
		// else if (elf_symbols->bind == STB_LOCAL)
		// 	return('t');
		// else
		// 	return('T');
	}
	else if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC + SHF_WRITE)
	{
		if (elf_symbols->bind == STB_WEAK)
		{
			if (elf_symbols->type == STT_OBJECT)
			{
				return (elf_symbols->shndx == SHN_UNDEF ? 'v' : 'V');
				// if (elf_symbols->shndx == SHN_UNDEF)
				// 	return('v');
				// else
				// 	return('V');
			}
			return (elf_symbols->shndx == SHN_UNDEF ? 'w' : 'W');
			// else if (elf_symbols->shndx == SHN_UNDEF)
			// 	return('w');
			// else
			// 	return('W');
		}
		else if (elf_symbols->bind == STB_GLOBAL)
		{
			if (elf_symbols->type == STT_OBJECT)		
			{
				return (elf_symbols->shndx == SHN_UNDEF ? 'G' : 'D');
				// if (elf_symbols->shndx == SHN_UNDEF)
				// 	return('G');
				// else
				// 	return('D');
			}
		}
		if (elf_symbols->bind == STB_LOOS)
			return('u');
		return (elf_symbols->bind == STB_LOCAL ? 'd' : 'D');
		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('d');
		// else
		// 	return('D');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE + SHF_EXECINSTR)
	{
		return (elf_symbols->bind == STB_LOCAL ? 't' : 'T');
		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('t');
		// else if (elf_symbols->bind == STB_GLOBAL)
		// 	return('T');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_MERGE)
	{
		return (elf_symbols->bind == STB_LOCAL ? 'r' : 'R');
		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('r');
		// else if (elf_symbols->bind == STB_GLOBAL)
		// 	return('R');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_MERGE + SHF_STRINGS)
	{
		return (elf_symbols->bind == STB_LOCAL ? 'r' : 'R');
		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('r');
		// else
		// 	return('R');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC)
	{
		if (elf_symbols->bind == STB_WEAK)
		{
			if (elf_symbols->type == STT_OBJECT)
			{
				return (elf_sections[elf_symbols->shndx].flag == SHN_UNDEF ? 'v' : 'V');

				// if (elf_sections[elf_symbols->shndx].flag == SHN_UNDEF)
				// 	return('v');
				// else
				// 	return('V');
			}
		}
		if (elf_symbols->bind == STB_LOOS)
			return('u');
		return (elf_symbols->bind == STB_LOCAL ? 'r' : 'R');
		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('r');
		// else 
		// 	return('R');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + (elf_sections[elf_symbols->shndx].flag & SHF_MASKPROC))
	{
		return (elf_symbols->bind == STB_LOCAL ? 'r' : 'R');

		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('r');
		// else
		// 	return('R');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE + (elf_sections[elf_symbols->shndx].flag & SHF_MASKPROC))
	{
		return (elf_symbols->bind == STB_LOCAL ? 'g' : 'G');

		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('g');
		// else
		// 	return('G');
	}
	return ('?');
}

char 	elf_type_nobits(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, t_elf_section_part *elf_sections)
{	
	if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC + SHF_WRITE)
	{
		if (elf_symbols->bind == STB_LOOS)
			return('u');
		if (elf_symbols->type == STT_OBJECT)
		{
			return(elf_symbols->bind == STB_LOCAL ? 'b' : (elf_symbols->bind == STB_GLOBAL) ? 'B' : 'V');
			// if (elf_symbols == STB_LOCAL)
			// 	return('b');
			// else if (elf_symbols->bind == STB_GLOBAL)
			// 	return('B');
			// else	
			// 	return('V');
		}
		return (elf_symbols->bind == STB_LOCAL ? 'b' : 'B');

		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('b');
		// else
		// 	return('B');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE + SHF_TLS)
	{
		return (elf_symbols->bind == STB_LOCAL ? 'b' : 'B');
		// if (elf_symbols->bind == STB_LOCAL)
		// 	return('b');
		// else
		// 	return('B');
	}
	else if (elf_sections[elf_symbols->shndx].flag == (elf_sections[elf_symbols->shndx].flag & SHF_MASKPROC) + SHF_ALLOC + SHF_WRITE)
	{
		if (elf_symbols->type == STT_OBJECT)
		{
			return (elf_symbols->bind == STB_LOCAL ? 'B' : 'S');
			// if (elf_symbols->bind == STB_LOCAL)
			// 	return('B');
			// else
			// 	return('S');
		}
		return (elf_symbols->bind == STB_LOCAL ? 's' : 'S');
		// else if (elf_symbols->bind == STB_LOCAL)
		// 	return('s');
		// else
		// 	return('S');
	}
	else
		return('?');
}
char    elf_symbol_type(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, Elf64_Sym *elf_sym, t_elf_section_part *elf_sections)
{
	// if (ft_strcmp(elf_symbols->name, "__do_global_dtors_aux_fini_array_entry") == 0)
	// {
	// 	ft_printf("name =\t%s\n", elf_symbols->name);
	// 	ft_printf("type =\t%u\n", elf_symbols->type);
	// 	ft_printf("bind =\t%u\n", elf_symbols->bind);
	// 	ft_printf("shndx =\t%u\n", elf_symbols->shndx);
	// 	ft_printf("value =\t%u\n", elf_symbols->value);
	// }
	// else
	// 	return ('.');
	(void)elf_sym;
	// if (elf_sections[elf_symbols->shndx].name == NULL)
	// {
	// 	if (elf_symbols->bind == STB_WEAK)
	// 	{
	// 		if (elf_symbols->type == STT_OBJECT)
	// 			return ('v');
	// 		return (elf_symbols->shndx == SHN_UNDEF ? 'w' : 'W');
	// 	}
	// 	else if (elf_symbols->bind == STB_LOCAL && elf_symbols->type == STT_NOTYPE)
	// 		return ('0');
	// 	if (elf_symbols->shndx == SHN_UNDEF)
	// 		return (elf_symbols->bind == STB_WEAK ? 'w' : 'U');
	// 	break ;
	// }
	if (elf_symbols->bind == STB_GNU_UNIQUE) // if (elf_symbols->bind == STB_LOOS)
		return('u');
	// else if (elf_symbols->type == STT_OBJECT)
	// 	return (elf_symbols->bind == STB_LOCAL ? 't' : 'T');
	else if (elf_symbols->bind == STB_WEAK)
	{
		return (elf_symbols->shndx == SHN_UNDEF ? 'w' : 'W');
		// if (elf_symbols->shndx == SHN_UNDEF)
		// 	return('w');
		// return('W');
	}
	else if (elf_symbols->bind == STB_WEAK && elf_symbols->type == STT_OBJECT)
	{
		return (elf_symbols->shndx == SHN_UNDEF ? 'v' : 'V');

		// if (elf_symbols->shndx == SHN_UNDEF)
		// 	return('v');
		// return('V');
	}
	else if (elf_symbols->shndx == SHN_UNDEF)
		return('U');
	else if (elf_symbols->shndx == SHN_ABS)
		return('A');
	else if (elf_symbols->shndx == SHN_COMMON)
		return('C');
	else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_NOBITS)
		return(elf_type_nobits(elf_symbols, elf_shdr, elf_sections));
	else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_PROGBITS)
		return(elf_type_progbits(elf_symbols, elf_shdr, elf_sections));
	else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_DYNAMIC)
		return(elf_type_dynamic(elf_symbols, elf_shdr));
	else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_INIT_ARRAY
		|| elf_shdr[elf_symbols->shndx].sh_type == SHT_FINI_ARRAY)
		return(elf_type_initarray(elf_symbols, elf_shdr));
	else
		return('?');
}
