#include "../includes/ft_nm.h"
char elf_type_initarray(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr)
{
	if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC + SHF_WRITE)
	{
		if (elf_symbols->bind == STB_LOCAL)
			return('t');
		else
			return('T');
	}
	else
		return('?');
}
char elf_type_dynamic(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr)
{
	if (elf_shdr[elf_symbols->shndx].sh_flags == (SHF_ALLOC + SHF_WRITE))
	{	
		if (elf_symbols->bind == STB_LOCAL)
			return('d');
		else
			return('D');
	}
	else if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC)
	{
		if (elf_symbols->bind == STB_LOCAL)
			return('r');
		else
			return('R');
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
			if (elf_symbols->shndx == SHN_UNDEF)
				elf_symbols->sym_type = 'w';
			return('W');
		}
		else if (elf_symbols->bind == STB_LOCAL)
			return('t');
		else
			return('T');
	}
	else if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC + SHF_WRITE)
	{
		if (elf_symbols->bind == STB_WEAK)
		{
			if (elf_symbols->type == STT_OBJECT)
			{
				if (elf_symbols->shndx == SHN_UNDEF)
					return('v');
				else
					return('V');
			}
			else if (elf_symbols->shndx == SHN_UNDEF)
				return('w');
			else
				return('W');
		}
		else if (elf_symbols->bind == STB_GLOBAL)
		{
			if (elf_symbols->type == STT_OBJECT)		
			{
				if (elf_symbols->shndx == SHN_UNDEF)
					return('G');
				else
					return('D');
			}
		}
		if (elf_symbols->bind == STB_LOOS)
			return('u');
		if (elf_symbols->bind == STB_LOCAL)
			return('d');
		else
			return('D');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE + SHF_EXECINSTR)
	{
		if (elf_symbols->bind == STB_LOCAL)
			return('t');
		else if (elf_symbols->bind == STB_GLOBAL)
			return('T');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_MERGE)
	{
		if (elf_symbols->bind == STB_LOCAL)
			return('r');
		else if (elf_symbols->bind == STB_GLOBAL)
			return('R');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_MERGE + SHF_STRINGS)
	{
		if (elf_symbols->bind == STB_LOCAL)
			return('r');
		else
			return('R');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC)
	{
		if (elf_symbols->bind == STB_WEAK)
		{
			if (elf_symbols->type == STT_OBJECT)
			{
				if (elf_sections[elf_symbols->shndx].flag == SHN_UNDEF)
					return('v');
				else
					return('V');
			}
		}
		if (elf_symbols->bind == STB_LOOS)
			return('u');
		if (elf_symbols->bind == STB_LOCAL)
			return('r');
		else 
			return('R');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + (elf_sections[elf_symbols->shndx].flag & SHF_MASKPROC))
	{
		if (elf_symbols->bind == STB_LOCAL)
			return('r');
		else
			return('R');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE + (elf_sections[elf_symbols->shndx].flag & SHF_MASKPROC))
	{
		if (elf_symbols->bind == STB_LOCAL)
			return('g');
		else
			return('G');
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
		if (elf_symbols->bind == STB_LOCAL)
			return('b');
		else
			return('B');
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE + SHF_TLS)
	{
		if (elf_symbols->bind == STB_LOCAL)
			return('b');
		else
			return('B');
	}
	else if (elf_sections[elf_symbols->shndx].flag == (elf_sections[elf_symbols->shndx].flag & SHF_MASKPROC) + SHF_ALLOC + SHF_WRITE)
	{
		if (elf_symbols->type == STT_OBJECT)
		{
			if (elf_symbols->bind == STB_LOCAL)
				return('B');
			else
				return('S');
		}
		else if (elf_symbols->bind == STB_LOCAL)
			return('s');
		else
			return('S');
	}
	else
		return('?');
}
char    elf_symbol_type(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, Elf64_Sym *elf_sym, t_elf_section_part *elf_sections)
{
	(void)elf_sym;
	if (elf_symbols->bind == STB_GNU_UNIQUE) // if (elf_symbols->bind == STB_LOOS)
		return('u');
	else if (elf_symbols->bind == STB_WEAK)
	{
		if (elf_symbols->shndx == SHN_UNDEF)
			return('w');
		return('W');
	}
	else if (elf_symbols->bind == STB_WEAK && elf_symbols->type == STT_OBJECT)
	{
		if (elf_symbols->shndx == SHN_UNDEF)
			return('v');
		return('V');
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
		|| elf_shdr[elf_symbols->shndx].sh_type == SHT_PREINIT_ARRAY)
		return(elf_type_initarray(elf_symbols, elf_shdr));
	else
		return('?');
}
