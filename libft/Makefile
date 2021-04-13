NAME 	= libft.a
CC 	= gcc
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

#-------------------------------------COLOR VARIABLE----------------------------#

red_li=$ \033[1;31m
red_da=$ \033[0;31m
grn_li=$ \033[1;32m
grn_da=$ \033[0;32m
yel=$ \033[1;33m
blu=$ \033[1;34m
mag=$ \033[1;35m
cyn=$ \033[1;36m
whi=$ \033[1;37m
end=$ \033[0m

#-------------------------------SRC/INC--------------------------------------------

LIBFT=  ft_abs ft_atoi ft_bzero ft_check_zero_d ft_dis ft_fdtoa ft_float_expo 		\
	ft_float_tools ft_fl_ok ft_free_arg ft_free_str ft_free_tab ft_get_fd 		\
	ft_get_sign ft_inf_nan ft_isalnum ft_isalpha ft_isascii ft_isdigit		\
 	ft_iseven ft_islowercase ft_isodd ft_isprint ft_isuppercase ft_itoa_base	\
	ft_itoa ft_lltoa_base ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_lstmap	\
	ft_lstnew ft_lstprint ft_lstsize ft_ltoa_base ft_memalloc ft_memccpy ft_memchr	\
	ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset ft_parse_flag ft_parse_len	\
 	ft_parse_precision ft_parse_type ft_parse_width ft_parsing ft_pow ft_printf	\
	ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd	\
	ft_putstr ft_putstr_fd ft_range ft_rec_c ft_sharp ft_sign_float ft_space_d	\
	ft_space_float ft_space_u ft_spec_zero_u ft_sp_switch_u ft_strcat ft_strchr	\
	ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdel_d ft_strdup ft_strequ		\
	ft_strisalpha ft_striter ft_striteri ft_strjoin ft_strjoin_free ft_strlcat	\
	ft_strlen ft_strlower ft_strmap ft_strmapi ft_strncat ft_strncmp ft_strncpy	\
	ft_strnequ ft_strnew ft_strnstr ft_strrchr ft_strrev ft_strsplit ft_strstr	\
	ft_strsub ft_strtrim ft_swap ft_tolower ft_toupper ft_type_char ft_type_conv	\
	ft_type_float ft_type_int ft_type_percent ft_type_pointer ft_type_string 	\
	ft_uitoa_base ft_ulitoa_base ft_ullitoa_base ft_unsigned ft_width_float 	\
	get_next_line_back get_next_line 

INC		= ft_printf.h libft.h get_next_line.h
SRC_FILES	= $(LIBFT:%=%.c) $(PRINTF:%=%.c)

#-------------------------PATH/OBJ/DEP---------------------------------------------

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

INC_FILES = $(addprefix $(INC_PATH), $(INC))
OBJ_FILES = $(patsubst %.c, $(OBJ_PATH)%.o, $(SRC_FILES))
DEPS=$(OBJ_FILES:%.o=%.d)

#---------------------------RULE----------------------------------------------------

.PHONY: all, clean, fclean, re

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_FILES): $(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c -I $(INC_PATH) $< -o $@
	@echo "Compilation of $(whi)$(notdir $<)$(grn_da) done.$(end)"

$(NAME): $(INC_FILES) $(OBJ_PATH) $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)
	@echo "$(grn_li)$(notdir $(NAME))$(grn_da) done.$(end)"

clean:
	@$(RM) -R $(OBJ_PATH) $(DEPS)
	@echo "$(red_li)Objects files of $(notdir $(NAME))$(red_da) removed.$(end)"

fclean: clean
	@$(RM) -R $(NAME)
	@echo "$(red_li)$(notdir $(NAME))$(red_da) removed.$(end)"

re: fclean
	@make all

