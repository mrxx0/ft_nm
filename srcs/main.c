#include "../includes/ft_nm.h"
#include <string.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

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

	
	if (fd != -1)
		close(fd);
	if (mmap_return != MAP_FAILED)
	{
		munmap((void*)mmap_return, stat.st_size);
	}
	return (1);
}
