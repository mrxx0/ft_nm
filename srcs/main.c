#include "../includes/ft_nm.h"
#include <string.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define TEST_HEADER_TYPE(type, value, name)\
	if ((type) == (value)) {\
		ft_printf("\t%s\n", (name));\
	}
int main(int argc, char **argv)
{
	if (argc > 2 || argc == 1)
		return (-1);
	int fd;
	struct stat stat = {0};
	char *mmap_return;
	fd = -1;

	fd = open(argv[1], O_RDONLY);
	mmap_return = NULL;
	if (fd < 0)
	{
		ft_printf("%s", "ERROR : fd is negative");
		if (fd != -1)
			close(fd);
		return (-1);
	}

	if (fstat(fd, &stat) != 0)
	{
		ft_printf("%s", "ERROR : return of stat is not OK");
		return (-1);
	}

	ft_printf("%s is open and it's size is : %d bytes\n", argv[1], stat.st_size);
	mmap_return = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (mmap_return == MAP_FAILED)
	{
		ft_printf("%s", "ERROR : MAP_FAILED");
		return (-1);
	}

	ft_printf("%s is mmaped correctly.\n", argv[1]);

	ft_printf("Checking if %s is an ELF file...\n\n", argv[1]);
	ft_printf("EI_MAG0 = %#x\n", (unsigned char)mmap_return[EI_MAG0]);
	ft_printf("EI_MAG1 = %c\n", (unsigned char)mmap_return[EI_MAG1]);
	ft_printf("EI_MAG2 = %c\n", (unsigned char)mmap_return[EI_MAG2]);
	ft_printf("EI_MAG3 = %c\n", (unsigned char)mmap_return[EI_MAG3]);

	if ((unsigned char)mmap_return[EI_MAG0] == 0x7f &&
			(unsigned char)mmap_return[EI_MAG1] == 'E' &&	
			(unsigned char)mmap_return[EI_MAG2] == 'L' &&	
			(unsigned char)mmap_return[EI_MAG3] == 'F')
		ft_printf("\n\t%s is an ELF file format.\n", argv[1]);
	else
		ft_printf("\n\t%s is not an ELF file format.\n", argv[1]); 

	ft_printf("\nChecking ELF class...\n");
	if ((unsigned char)mmap_return[EI_CLASS] == ELFCLASS64)
		ft_printf("\t%s is a 64 bits ELF\n", argv[1]);
	else if ((unsigned char)mmap_return[EI_CLASS] == ELFCLASS32)
		ft_printf("\t%s is a 32 bits ELF\n", argv[1]);
	else
		ft_printf("\t%s unknown ELF type.\n", argv[1]);

	ft_printf("\nChecking %s endian type...\n", argv[1]);
	if ((unsigned char)mmap_return[EI_DATA] == ELFDATA2LSB)
	{
		ft_printf("\t%s is for little-endian\n", argv[1]);
	}
	else
		ft_printf("\t%s is for big-endian\n", argv[1]);

	ft_printf("\nChecking if %s is compiled for Linux...\n", argv[1]);
	if ((unsigned char)mmap_return[EI_OSABI] == ELFOSABI_LINUX)
	{
		ft_printf("\t%s is LINUX binary\n", argv[1]);
	}
	else if ((unsigned char)mmap_return[EI_OSABI] == ELFOSABI_SYSV)
		ft_printf("\t%s is SYSB binary\n", argv[1]);
	else if ((unsigned char)mmap_return[EI_OSABI] == ELFOSABI_NONE)
		ft_printf("\t%s is NONE binary\n", argv[1]);

	ft_printf("Checking entry point for %s...\n", argv[1]);
	ft_printf("\t%s's entry point is at %lu\n",argv[1], ((Elf64_Ehdr *)mmap_return)->e_entry);

	ft_printf("Checking type of program headers in %s...\n", argv[1]);

	int i;

	i = 0;
	Elf64_Ehdr *eh = (Elf64_Ehdr *)mmap_return;
	while (i <eh->e_phnum)
	{
		Elf64_Phdr *ph = (Elf64_Phdr *)((char *)mmap_return + (eh->e_phoff + eh->e_phentsize * i));
		uint32_t type = ph->p_type;

		TEST_HEADER_TYPE(type, PT_NULL, "PT_NULL");
		TEST_HEADER_TYPE(type, PT_LOAD, "PT_LOAD");
		TEST_HEADER_TYPE(type, PT_DYNAMIC, "PT_DYNAMIC");
		TEST_HEADER_TYPE(type, PT_INTERP, "PT_INTERP");
		TEST_HEADER_TYPE(type, PT_NOTE, "PT_NOTE");
		TEST_HEADER_TYPE(type, PT_SHLIB, "PT_SHLIB");
		TEST_HEADER_TYPE(type, PT_PHDR, "PT_PHDR");
		TEST_HEADER_TYPE(type, PT_TLS, "PT_TLS");
		TEST_HEADER_TYPE(type, PT_NUM, "PT_NUM");
		TEST_HEADER_TYPE(type, PT_LOOS, "PT_LOOS");
		TEST_HEADER_TYPE(type, PT_GNU_EH_FRAME, "PT_GNU_EH_FRAME");
		TEST_HEADER_TYPE(type, PT_GNU_STACK, "PT_GNU_STACK");
		TEST_HEADER_TYPE(type, PT_GNU_RELRO, "PT_GNU_RELRO");
		TEST_HEADER_TYPE(type, PT_LOSUNW, "PT_LOSUNW");
		TEST_HEADER_TYPE(type, PT_SUNWBSS, "PT_SUNWBSS");
		TEST_HEADER_TYPE(type, PT_SUNWSTACK, "PT_SUNWSTACK");
		TEST_HEADER_TYPE(type, PT_HISUNW, "PT_HISUNW");
		TEST_HEADER_TYPE(type, PT_HIOS, "PT_HIOS");
		TEST_HEADER_TYPE(type, PT_LOPROC, "PT_LOPROC");
		TEST_HEADER_TYPE(type, PT_HIPROC, "PT_HIPROC");
		i++;	
	}
	
	ft_printf("Checking type of section headers in %s...\n", argv[1]);
	/*Elf64_Ehdr *eh = (Elf64_Ehdr*)mmap_return;
	i = 0;
	while (i < eh->e_phnum)
	{
		Elf64_Phdr
	}
	Elf64_Ehdr *elf_header = (Elf64_Ehdr *)mmap_return;
	Elf64_Shdr *shstrtab_header = (Elf64_Shdr *)((char *)mmap_return + (eh->e_shoff + eh->e_phentsize * eh->e_shstrndx));
	const char *shstrtab = (const char *)mmap_return + shstrtab_header->sh_offset;
	*/

	if (fd != -1)
		close(fd);
	if (mmap_return != MAP_FAILED)
	{
		munmap((void*)mmap_return, stat.st_size);
	}
	return (1);
}

