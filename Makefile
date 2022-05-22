CC = cc
CFLAGS = -Wall -Werror -Wextra 
INCLUDE = -I./inc

PUSH_SWAP = inc/push_swap.h 
CHECKER_BONUS = inc/checker_bonus.h

FILES = ft_atoi.o	\
	ft_printf.o	\
	ft_printf_utils.o	\
	ft_printf_utils2.o	\
	ft_split.o  \
	ft_strdup.o  \
	push_swap.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlcpy.o \
	ft_strlen.o \
	parsing.o \
	parsing2.o \
	operations.o \
	operations2.o \
	sort_utils.o \
	sort_big_part1.o \
	sort_big_part2.o \
	sorting.o

FILES_B = ft_atoi.o	\
		ft_split.o  \
		ft_strdup.o  \
		checker_bonus.o \
		operations_bonus.o \
		operations_bonus2.o \
		outils_bonus.o \
		parsing_bonus.o \
		parsing_bonus2.o \
		get_next_line.o \
		ft_strjoin.o \
		ft_strlcat.o \
		ft_strlcpy.o \
		ft_strlen.o 


B_DIR = build

OBJ = $(addprefix $(B_DIR)/, $(FILES))
OBJ_B = $(addprefix $(B_DIR)/bonus/, $(FILES_B))

NAME = push_swap
NAME_B = checker

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(MFLAGS) $^ -o $@
	@echo "\033[30;1m---> \033[0mPush_Swap (Sorting Algorithm) V2.0 \033[32;1m [OK] \033[0m"
	

bonus : $(OBJ_B)
	$(CC) $(MFLAGS) $^ -o $(NAME_B)
	@echo "\033[30;1m---> \033[0mChecker for Push_Swap (Sorting Algorithm) V2.0 \033[32;1m [OK] \033[0m"

$(B_DIR)/bonus/%.o: src/bonus/%.c $(CHECKER_BONUS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c  $<

$(B_DIR)/%.o: src/%.c $(PUSH_SWAP)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c  $<

clean :
	@echo "\033[30;1m---> \033[0mObject files clean\033[32;1m [DONE] \033[0m"
	rm -rf $(B_DIR)  

fclean : clean
	@echo "\033[30;1m---> \033[0mBinary files clean\033[32;1m [DONE] \033[0m"
	rm $(NAME) $(NAME_B)

re : fclean all

.PHONY : all bonus clean fclean re 