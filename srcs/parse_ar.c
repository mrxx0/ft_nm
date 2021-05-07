#include "../includes/ft_nm.h"

void skip_file_identifier(int *file_identifier, char *mmap_return)
{
    while (*file_identifier >= 0 && mmap_return[*file_identifier] == ' ')
        *file_identifier = *file_identifier - 1;
}

int	parse_ar(char *mmap_return, char *file_offset)
{
    struct ar_hdr *ar;
    char    *str_tab = NULL;

    ar = (struct ar_hdr *)(mmap_return + SARMAG);
    ft_printf("mmap_return = [%s]\n", mmap_return);

    mmap_return = mmap_return + SARMAG;
    ft_printf("mmap_return + SARMAG = [%s]\n", mmap_return);
 
    mmap_return = mmap_return + sizeof(*ar) ;
    ft_printf("mmap_return + sizeof(*ar) = [%s]\n", mmap_return -1);
    ft_printf("sizeof(*ar) = [%u]\n", sizeof(*ar));

    mmap_return = mmap_return + ft_atoi(ar->ar_size);
    ft_printf("mmap_return + ft_atoi(ar->ar_size) = [%s]\n", mmap_return);
    ft_printf("ft_atoi(ar->ar_size) = [%u]\n", ft_atoi(ar->ar_size));

    // ft_printf("ar_name = [%s]\n", ar->ar_name);
    // ft_printf("ar_date = [%s]\n", ar->ar_date);
    // ft_printf("ar_uid = [%s]\n", ar->ar_uid);
    // ft_printf("ar_gid = [%s]\n", ar->ar_gid);
    // ft_printf("ar_mode = [%s]\n", ar->ar_mode);
    // ft_printf("ar_size = [%s]\n", ar->ar_size);
    // ft_printf("ar_fmag = [%s]\n", ar->ar_fmag);

    mmap_return = mmap_return + SARMAG + sizeof(*ar) + ft_atoi(ar->ar_size);
    ft_printf("mmap_return = [%s]\n", mmap_return);
    int file_identifier = 16;
    int size = 0;
    skip_file_identifier(&file_identifier, mmap_return);
    if (file_identifier == 1 
    && mmap_return[0] == '/' && mmap_return[1] == '/')
    {
        str_tab = mmap_return;
        ar = (struct ar_hdr *)mmap_return;
        size = ft_atoi(ar->ar_size);
        mmap_return = mmap_return + sizeof(*ar) + size;
    }
    // int i = 0;
    // ft_printf("[%c] \t [%c]\n", mmap_return[0], mmap_return[1]);
    // if (mmap_return[i] == '/'&& mmap_return[i + 1] == '/')
    //     ft_printf("Check char OK\n");
    // i = 2;
    // while (mmap_return[i] == ' ')
    //     i++;
    // ft_printf("mmap_return = [%s]\n", mmap_return + i);
    // ft_printf("i = [%d]\n", i);
    // ft_printf("mmap_return = [%s]\n", mmap_return + 16);

    // mmap_return = mmap_return + SARMAG;
    // ft_printf("mmap_return = [%s]\n", mmap_return);
    
    // mmap_return = mmap_return + ft_atoi(ar->ar_size);
    // ft_printf("mmap_return = [%s]\n", mmap_return);

    // mmap_return = mmap_return + sizeof(struct ar_hdr);
    // ft_printf("mmap_return = [%s]\n", mmap_return);
    if (mmap_return > file_offset)
		return (ft_perror("File is corrupted\n", 0));
    
    return (EXIT_SUCCESS);
}