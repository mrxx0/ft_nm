#include "../includes/ft_nm.h"

void    elf_symbol_type(t_elf_symbol_part *elf_symbols, Elf64_Shdr *elf_shdr, Elf64_Sym *elf_sym)
{
    (void)elf_sym;
    elf_symbols->sym_type = '\0';
    if (elf_symbols->bind == STB_GNU_UNIQUE)
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

    
    (void)elf_shdr;
    return ;
}