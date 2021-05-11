#include "../includes/ft_nm.h"

uint32_t			reverse32(uint32_t x, short reverse) {
	int				i = 0;
	uint32_t		y = 0;
	unsigned char	*ptr_x, *ptr_y;
	size_t size = sizeof(x);

	if (!reverse)
		return (x);
	ptr_x = (unsigned char *)&x;
	ptr_y = (unsigned char *)&y;
	while (--size)
		ptr_y[i++] = ptr_x[size];
	ptr_y[i++] = ptr_x[size];
	return (y);
}

int	parse_elf_32(char *mmap_return, char *file_offset)
{
	(void)file_offset;
	Elf32_Ehdr		*elf_header;
	Elf32_Shdr		*elf_shdr;
	int8_t			file_endian = 0;
	_Bool			system_endian = 0;
	_Bool			reverse = 0;
	char			*elf_strtable;
	// t_elf_section_part	*elf_sections = NULL;

	elf_header = (Elf32_Ehdr *)mmap_return;
	file_endian = get_endian_file_32(elf_header);
	if (file_endian == FAILURE)
		return(ft_perror("File format not recognized\n", 0));
	system_endian = get_endian_system();
	reverse = need_to_reverse(file_endian, system_endian);
	if (reverse)
		ft_printf("NEED TO REVERSE\n");
	// elf_shdr = (Elf32_Shdr *)(mmap_return + (uint32_t)reverse_for_32(elf_header->e_shoff, reverse));
	elf_shdr = (Elf32_Shdr *)(mmap_return + reverse_for_32(elf_header->e_shoff, reverse));
		ft_printf("before\n");
	// elf_strtable = mmap_return + reverse_for_32(elf_shdr[reverse_for_32(elf_header->e_shstrndx, reverse)].sh_offset, reverse);
	// printf("shstrndx = %u\n", elf_header->e_shstrndx);
	// printf("shstrndx = %u\n", reverse_for_32(elf_header->e_shstrndx, reverse));
	printf("sh_offset = %u\n", elf_shdr[elf_header->e_shstrndx].sh_offset);
	// printf("sh_offset = %u\n", reverse_for_32(elf_shdr[reverse_for_32(elf_header->e_shstrndx, reverse)].sh_offset, reverse));
	printf("%u\n", reverse_for_32(elf_shdr[elf_header->e_shstrndx].sh_offset, reverse));
	printf("%u\n", reverse_for_32(elf_header->e_shstrndx, reverse));
	printf("%u\n", elf_shdr[2572100].sh_offset);

	(void)elf_strtable;
	// elf_strtable = mmap_return + elf_shdr[reverse32(elf_header->e_shstrndx, reverse)].sh_offset;
		ft_printf("ok\n");

	// elf_strtable = mmap_return + (elf_shdr[elf_header->e_shstrndx].sh_offset);
		// ft_printf("ok\n");

	// elf_sections = stock_elf32_sections((uint16_t)reverse_for_32(elf_header->e_shnum, reverse), elf_shdr, elf_strtable, reverse);
		// ft_printf("okok\n");

	return (EXIT_SUCCESS);
}
