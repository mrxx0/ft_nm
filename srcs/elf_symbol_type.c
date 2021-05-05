#include "../includes/ft_nm.h"
// char elf_type_initarray(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr)
// {
// 	if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC + SHF_WRITE)
// 	{
// 		return (elf_symbols->bind == STB_LOCAL ? 't' : 'T');
// 	}
// 	else
// 		return('?');
// }
// char elf_type_dynamic(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr)
// {
// 	if (elf_shdr[elf_symbols->shndx].sh_flags == (SHF_ALLOC + SHF_WRITE))
// 	{	
// 		return (elf_symbols->bind == STB_LOCAL ? 'd' : 'D');
// 	}
// 	else if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC)
// 	{
// 		return (elf_symbols->bind == STB_LOCAL ? 'r' : 'R');
// 	}
// 	else
// 		return('?');
// }
// char 	elf_type_progbits(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, t_elf_section_part *elf_sections)
// {
// 	if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_EXECINSTR)
// 	{
// 		if (elf_symbols->bind == STB_WEAK)
// 		{
// 			return (elf_symbols->shndx == SHN_UNDEF ? 'w' : 'W');
// 		}
// 		return (elf_symbols->bind == STB_LOCAL ? 't' : 'T');
// 	}
// 	else if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC + SHF_WRITE)
// 	{
// 		if (elf_symbols->bind == STB_WEAK)
// 		{
// 			if (elf_symbols->type == STT_OBJECT)
// 			{
// 				return (elf_symbols->shndx == SHN_UNDEF ? 'v' : 'V');
// 			}
// 			return (elf_symbols->shndx == SHN_UNDEF ? 'w' : 'W');
// 		}
// 		else if (elf_symbols->bind == STB_GLOBAL)
// 		{
// 			if (elf_symbols->type == STT_OBJECT)		
// 			{
// 				return (elf_symbols->shndx == SHN_UNDEF ? 'G' : 'D');
// 			}
// 		}
// 		if (elf_symbols->bind == STB_LOOS)
// 			return('u');
// 		return (elf_symbols->bind == STB_LOCAL ? 'd' : 'D');
// 	}
// 	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE + SHF_EXECINSTR)
// 	{
// 		return (elf_symbols->bind == STB_LOCAL ? 't' : 'T');
// 	}
// 	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_MERGE)
// 	{
// 		return (elf_symbols->bind == STB_LOCAL ? 'r' : 'R');
// 	}
// 	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_MERGE + SHF_STRINGS)
// 	{
// 		return (elf_symbols->bind == STB_LOCAL ? 'r' : 'R');
// 	}
// 	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC)
// 	{
// 		if (elf_symbols->bind == STB_WEAK)
// 		{
// 			if (elf_symbols->type == STT_OBJECT)
// 			{
// 				return (elf_sections[elf_symbols->shndx].flag == SHN_UNDEF ? 'v' : 'V');
// 			}
// 		}
// 		if (elf_symbols->bind == STB_LOOS)
// 			return('u');
// 		return (elf_symbols->bind == STB_LOCAL ? 'r' : 'R');
// 	}
// 	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + (elf_sections[elf_symbols->shndx].flag & SHF_MASKPROC))
// 	{
// 		return (elf_symbols->bind == STB_LOCAL ? 'r' : 'R');
// 	}
// 	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE + (elf_sections[elf_symbols->shndx].flag & SHF_MASKPROC))
// 	{
// 		return (elf_symbols->bind == STB_LOCAL ? 'g' : 'G');
// 	}
// 	return ('?');
// }

// char 	elf_type_nobits(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, t_elf_section_part *elf_sections)
// {	
// 	if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC + SHF_WRITE)
// 	{
// 		if (elf_symbols->bind == STB_LOOS)
// 			return('u');
// 		if (elf_symbols->type == STT_OBJECT)
// 		{
// 			return(elf_symbols->bind == STB_LOCAL ? 'b' : (elf_symbols->bind == STB_GLOBAL) ? 'B' : 'V');
// 		}
// 		return (elf_symbols->bind == STB_LOCAL ? 'b' : 'B');
// 	}
// 	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE + SHF_TLS)
// 	{
// 		return (elf_symbols->bind == STB_LOCAL ? 'b' : 'B');
// 	}
// 	else if (elf_sections[elf_symbols->shndx].flag == (elf_sections[elf_symbols->shndx].flag & SHF_MASKPROC) + SHF_ALLOC + SHF_WRITE)
// 	{
// 		if (elf_symbols->type == STT_OBJECT)
// 		{
// 			return (elf_symbols->bind == STB_LOCAL ? 'B' : 'S');
// 		}
// 		return (elf_symbols->bind == STB_LOCAL ? 's' : 'S');
// 	}
// 	else
// 		return('?');
// }
char    elf_symbol_type(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, Elf64_Sym *elf_sym, t_elf_section_part *elf_sections)
{
	(void)elf_sym;
	if (elf_symbols->shndx == SHN_ABS)
		return ('A');
	else if (elf_symbols->type == STT_OBJECT && elf_shdr[elf_symbols->shndx].sh_type == SHT_NOBITS && elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE)
		return ('B');
	else if (elf_symbols->shndx == SHN_COMMON)
		return ('C');
	else if (((elf_symbols->type == STT_OBJECT || elf_symbols->type == STT_NOTYPE)
	&& elf_shdr[elf_symbols->shndx].sh_type == SHT_PROGBITS
	&& elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE)
	|| elf_shdr[elf_symbols->shndx].sh_type == SHT_DYNAMIC)
		return ('D');
	else if (elf_symbols->type == STT_LOOS && elf_shdr[elf_symbols->shndx].sh_type == SHT_PROGBITS &&elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_EXECINSTR)
		return ('i');
	else if ((elf_symbols->type == STT_NOTYPE || elf_symbols->type == STT_OBJECT) && elf_shdr[elf_symbols->shndx].sh_type == SHT_PROGBITS &&elf_sections[elf_symbols->shndx].flag == 0)
		return ('N');
	else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_PROGBITS && elf_sections[elf_symbols->shndx].flag == SHF_ALLOC)
		return ('R');
	else
		return ('?');
	// if (elf_symbols->bind == STB_GNU_UNIQUE) // if (elf_symbols->bind == STB_LOOS)
	// 	return('u');
	// else if (elf_symbols->bind == STB_WEAK)
	// {
	// 	return (elf_symbols->shndx == SHN_UNDEF ? 'w' : 'W');
	// }
	// else if (elf_symbols->bind == STB_WEAK && elf_symbols->type == STT_OBJECT)
	// {
	// 	return (elf_symbols->shndx == SHN_UNDEF ? 'v' : 'V');
	// }
	// else if (elf_symbols->shndx == SHN_UNDEF)
	// 	return('U');
	// else if (elf_symbols->shndx == SHN_ABS)
	// 	return('A');
	// else if (elf_symbols->shndx == SHN_COMMON)
	// 	return('C');
	// else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_NOBITS)
	// 	return(elf_type_nobits(elf_symbols, elf_shdr, elf_sections));
	// else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_PROGBITS)
	// 	return(elf_type_progbits(elf_symbols, elf_shdr, elf_sections));
	// else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_DYNAMIC)
	// 	return(elf_type_dynamic(elf_symbols, elf_shdr));
	// else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_INIT_ARRAY
	// 	|| elf_shdr[elf_symbols->shndx].sh_type == SHT_FINI_ARRAY)
	// 	return(elf_type_initarray(elf_symbols, elf_shdr));
	// else
	// 	return('?');
}
