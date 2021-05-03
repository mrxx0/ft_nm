#include "../includes/ft_nm.h"
void 	elf_type_progbits(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, t_elf_section_part *elf_sections)
{
	if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_EXECINSTR)
	{
		if (elf_symbols->bind == STB_WEAK)
		{
			elf_symbols->sym_type = 'W';
			if (elf_symbols->shndx == SHN_UNDEF)
				elf_symbols->sym_type = 'w';
		}
		else if (elf_symbols->bind == STB_LOCAL)
			elf_symbols->sym_type = 't';
		else
			elf_symbols->sym_type = 'T';
	}
	else if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC + SHF_WRITE)
	{
		if (elf_symbols->bind == STB_WEAK)
		{
			if (elf_symbols->type == STT_OBJECT)
			{
				if (elf_symbols->shndx == SHN_UNDEF)
					elf_symbols->sym_type = 'v';
				else
					elf_symbols->sym_type = 'V';
			}
			else if (elf_symbols->shndx == SHN_UNDEF)
				elf_symbols->sym_type = 'w';
			else
				elf_symbols->sym_type = 'W';
		}
		else if (elf_symbols->bind == STB_GLOBAL)
		{
			if (elf_symbols->type == STT_OBJECT)		
			{
				if (elf_symbols->shndx == SHN_UNDEF)
					elf_symbols->sym_type = 'G';
				else
					elf_symbols->sym_type = 'D';
			}
		}
		else if (elf_symbols->bind == STB_LOOS)
		{
			elf_symbols->sym_type = 'u';
			if (elf_symbols->bind == STB_LOCAL)
				elf_symbols->sym_type = 'd';
			else
				elf_symbols->sym_type = 'D';
		}
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_WRITE + SHF_EXECINSTR)
	{
		if (elf_symbols->bind == STB_LOCAL)
			elf_symbols->sym_type = 't';
		else if (elf_symbols->bind == STB_GLOBAL)
			elf_symbols->sym_type = 'T';
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_MERGE)
	{
		if (elf_symbols->bind == STB_LOCAL)
			elf_symbols->sym_type = 'r';
		else if (elf_symbols->bind == STB_GLOBAL)
			elf_symbols->sym_type = 'R';
	}
	else if (elf_sections[elf_symbols->shndx].flag == SHF_ALLOC + SHF_MERGE + SHF_STRINGS)
	{
		if (elf_symbols->bind == STB_LOCAL)
			elf_symbols->sym_type = 'r';
		else if (elf_symbols->bind == STB_GLOBAL)
			elf_symbols->sym_type = 'R';
	}

}
void 	elf_type_nobits(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, t_elf_section_part *elf_sections)
{	
	if (elf_sections[elf_symbols->shndx].flag == SHF_WRITE + SHF_ALLOC + SHF_TLS)
		{
			if (elf_symbols->bind == STB_LOCAL)
				elf_symbols->sym_type = 'b';
			else if (elf_symbols->bind == STB_GLOBAL)
				elf_symbols->sym_type = 'B';
		}
	else if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC 
			&& elf_shdr[elf_symbols->shndx].sh_flags ==  SHF_WRITE)
	{
		if (elf_symbols->bind == STB_LOOS)
			elf_symbols->sym_type = 'u';
		if (elf_symbols->type == STT_OBJECT)
		{
			if (elf_symbols == STB_LOCAL)
				elf_symbols->sym_type = 'b';
			else if (elf_symbols->bind == STB_GLOBAL)
				elf_symbols->sym_type = 'B';
			else	
				elf_symbols->sym_type = 'V';
		}
		else if (elf_symbols->bind == STB_LOCAL)
			elf_symbols->sym_type = 'b';
		else if (elf_symbols->bind == STB_GLOBAL)
			elf_symbols->sym_type = 'B';
	}
	else if (elf_sections[elf_symbols->shndx].flag == (elf_sections[elf_symbols->shndx].flag & SHF_MASKPROC) + SHF_ALLOC + SHF_WRITE)
	{
		if (elf_symbols->type == STT_OBJECT)
		{
			if (elf_symbols->bind == STB_LOCAL)
				elf_symbols->sym_type = 'B';
			else if (elf_symbols->bind == STB_GLOBAL)
				elf_symbols->sym_type = 'S';
		}
		else if (elf_symbols->bind == STB_LOCAL)
			elf_symbols->sym_type = 's';
		else if (elf_symbols->bind == STB_GLOBAL)
			elf_symbols->sym_type = 'S';
	}
}
void    elf_symbol_type(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, Elf64_Sym *elf_sym, t_elf_section_part *elf_sections)
{
	(void)elf_sym;
	if (elf_symbols->bind == STB_GNU_UNIQUE) // if (elf_symbols->bind == STB_LOOS)
		elf_symbols->sym_type = 'u';
	else if (elf_symbols->bind == STB_WEAK)
	{
		elf_symbols->sym_type = 'W';
		if (elf_symbols->shndx == SHN_UNDEF)
			elf_symbols->sym_type = 'w';
	}
	else if (elf_symbols->bind == STB_WEAK && elf_symbols->type == STT_OBJECT)
	{
		elf_symbols->sym_type = 'V';
		if (elf_symbols->shndx == SHN_UNDEF)
			elf_symbols->sym_type = 'v';
	}
	else if (elf_symbols->shndx == SHN_UNDEF)
		elf_symbols->sym_type = 'U';
	else if (elf_symbols->shndx == SHN_ABS)
		elf_symbols->sym_type = 'A';
	else if (elf_symbols->shndx == SHN_COMMON)
		elf_symbols->sym_type = 'C';
	else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_NOBITS)
		elf_type_nobits(elf_symbols, elf_shdr, elf_sections);
	else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_PROGBITS)
		elf_type_progbits(elf_symbols, elf_shdr, elf_sections);
	// else if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC)
	// {
	// 	if (elf_symbols->bind == STB_LOCAL)
	// 		elf_symbols->sym_type = 'r';
	// 	else
	// 		elf_symbols->sym_type = 'R';
	// }
	// else if (elf_shdr[elf_symbols->shndx].sh_flags == (SHF_ALLOC + SHF_WRITE))
	// {
	// 	if (elf_symbols->bind == STB_LOCAL)
	// 		elf_symbols->sym_type = 'd';
	// 	else
	// 		elf_symbols->sym_type = 'D';
	// }
	// else if (elf_shdr[elf_symbols->shndx].sh_type == SHT_DYNAMIC)
	// {
	// 	if (elf_shdr[elf_symbols->shndx].sh_flags == (SHF_ALLOC + SHF_WRITE))
	// 	{	
	// 	if (elf_symbols->bind == STB_LOCAL)
	// 	elf_symbols->sym_type = 'd';
	// 	else
	// 	elf_symbols->sym_type = 'D';
	// 	}
	// }
	// else if (elf_shdr[elf_symbols->shndx].sh_flags == SHF_ALLOC)
	// 	{
	// 	if (elf_symbols->bind == STB_LOCAL)
	// 	elf_symbols->sym_type = 'r';
	// 	else
	// 	elf_symbols->sym_type = 'R';
	// 	}
	// }

//  else if (elf_sections[elf_symbols->shndx].flag == ((elf_sections[elf_symbols->shndx].flag & SHF_MASKOS) | (SHF_ALLOC | SHF_WRITE)))
//      {
//      if (elf_symbols->bind == STB_LOCAL)
//      elf_symbols->sym_type = 'g';
//      else
//      elf_symbols->sym_type = 'G';
//      }
	else
		elf_symbols->sym_type = '?';
return ;
}
