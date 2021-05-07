#include "../includes/ft_nm.h"

int	parse_ar(char *mmap_return, char *file_offset)
{
    struct ar_hdr *ar;
    ft_printf("mmap_return + SARMAG = [%s]\n", mmap_return + SARMAG);

    ar = (struct ar_hdr *)(mmap_return + SARMAG);
    ft_printf("ar_name = [%s]\n", ar->ar_name);
    ft_printf("ar_date = [%s]\n", ar->ar_date);
    ft_printf("ar_uid = [%s]\n", ar->ar_uid);
    ft_printf("ar_gid = [%s]\n", ar->ar_gid);
    ft_printf("ar_mode = [%s]\n", ar->ar_mode);
    ft_printf("ar_size = [%s]\n", ar->ar_size);
    ft_printf("ar_fmag = [%s]\n", ar->ar_fmag);

    mmap_return = mmap_return + SARMAG;
    ft_printf("mmap_return = [%s]\n", mmap_return);
    
    mmap_return = mmap_return + ft_atoi(ar->ar_size);
    ft_printf("mmap_return = [%s]\n", mmap_return);
    if (mmap_return > file_offset)
		return (ft_perror("File is corrupted\n", 0));
    
    return (EXIT_SUCCESS);
}