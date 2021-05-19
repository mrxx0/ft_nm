#include "../includes/ft_nm.h"

char *ft_strndup(char *s1, size_t n)
{
    char *ret = NULL;
    char *tmp = NULL;

    ret = malloc(sizeof(char *) * n + 1);
    if (!ret)
        return (NULL);
    tmp = ret;
    while((*ret++ = *s1++) && n--);
    *ret = '\0';
    return (tmp);
}

void    print_ar(char *name)
{
    printf("\n");
    while (*name != '/')
    {
        printf("%c", *name);
        name++;
    }
    printf(":\n");
}

char *get_name(char **str_tab)
{
    int     i;
    char    *name;
    char    *tmp;

    i = 0;
    name = NULL;
    while (!(ft_isalpha(**str_tab)))
        (*str_tab)++;
    tmp = *str_tab;
    while (*tmp != '/')
        tmp++;
    i = tmp - *str_tab;
    if (!(name = ft_strndup(*str_tab, i)))
        return (MALLOC_FAILED);
    *str_tab = *str_tab + i;
    return (name);
}

int skip_file_identifier(char *mmap_return)
{
    int file_identifier = 16;

    while (file_identifier >= 0 && mmap_return[file_identifier] == ' ')
        file_identifier = file_identifier - 1;
    return (file_identifier);
}

int	parse_ar(char *mmap_return, char *file_offset, char *file_name)
{
    if (mmap_return > file_offset)
		return (ft_perror("File is corrupted\n", 0));
    struct ar_hdr *ar;
    char    *str_tab = NULL;

    ar = (struct ar_hdr *)(mmap_return + SARMAG);
    // ft_printf("mmap_return = [%s]\n", mmap_return);
    

    mmap_return = mmap_return + SARMAG;
    // ft_printf("mmap_return + SARMAG = [%s]\n", mmap_return);
 
    mmap_return = mmap_return + sizeof(*ar) ;
    // ft_printf("mmap_return + sizeof(*ar) = [%s]\n", mmap_return -1);
    // ft_printf("sizeof(*ar) = [%u]\n", sizeof(*ar));

    mmap_return = mmap_return + ft_atoi(ar->ar_size);
    // ft_printf("mmap_return + ft_atoi(ar->ar_size) = [%s]\n", mmap_return);
    // ft_printf("ft_atoi(ar->ar_size) = [%u]\n", ft_atoi(ar->ar_size));

    // ft_printf("ar_name = [%s]\n", ar->ar_name);
    // ft_printf("ar_date = [%s]\n", ar->ar_date);
    // ft_printf("ar_uid = [%s]\n", ar->ar_uid);
    // ft_printf("ar_gid = [%s]\n", ar->ar_gid);
    // ft_printf("ar_mode = [%s]\n", ar->ar_mode);
    // ft_printf("ar_size = [%s]\n", ar->ar_size);
    // ft_printf("ar_fmag = [%s]\n", ar->ar_fmag);

    // mmap_return = mmap_return + SARMAG + sizeof(*ar) + ft_atoi(ar->ar_size);
    // ft_printf("mmap_return = [%s]\n", mmap_return);
    
    if (skip_file_identifier(mmap_return) == 1 
    && mmap_return[0] == '/' && mmap_return[1] == '/')
    {
        str_tab = mmap_return;
        ar = (struct ar_hdr *)mmap_return;
        mmap_return = mmap_return + sizeof(*ar) + ft_atoi(ar->ar_size);
    }
   // ft_printf("strtab = %s\n", str_tab);
    int len = 0;
    char *name;
    while (mmap_return < file_offset)
    {
        // ft_printf("mmap_return < file_offset = %d\n", mmap_return < file_offset);
        // ft_printf("mmap_return = %u\n", mmap_return);
        // ft_printf("file_offset = %u\n\n", file_offset);

        len = 0;
        name = NULL;
        ar = (struct ar_hdr*)mmap_return;
        if (validate_elf_type(mmap_return + sizeof(*ar), file_offset) == 0)
            return (ft_perror("File format not recognized\n", 0));
        while (ar->ar_name[len] != '/')
            len++;
        if (len == 0)
        {   
            if (!(name = get_name(&str_tab)))
		        return (ft_perror("Malloc failed to allocate memory\n.", 0));
           print_ar(name);
        }
        else
           print_ar(ar->ar_name);
        if (check_file_is_elf(mmap_return + sizeof(*ar), file_offset, file_name) == EXIT_FAILURE)
          return (ft_perror("Corrupted\n", 0));
        mmap_return = mmap_return + sizeof(struct ar_hdr) + ft_atoi(ar->ar_size);
        free(name);
    }
    // ft_printf("mmap_return = %u\n", mmap_return);

    // ft_printf("Going for %d\n", str_idx);
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
    
    
    return (EXIT_SUCCESS);
}