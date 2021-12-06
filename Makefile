SRCS		= ft_stack.c			\
			  g_error.c				\
			  main.c				\
			  ft_instruction_a.c	\
			  ft_instruction_b.c	\
			  ft_instruction_ab.c	\
			  ft_instruction.c		\
			  algo_under_6.c		\
			  push_swap.c			\
			  push_swap2.c			\
			  utils.c				\
			  mediane.c

B_SRCS		= ./bonus/checker.c						\
			  ./bonus/check_instruction.c			\
			  ./bonus/ft_instruction_a_bonus.c		\
			  ./bonus/ft_instruction_ab_bonus.c		\
			  ./bonus/ft_instruction_b_bonus.c		\
			  ./bonus/ft_instruction_bonus.c		\
			  ./bonus/ft_stack_bonus.c				\
			  ./bonus/g_error_bonus.c				\
			  ./bonus/utils_bonus.c

OBJS		= ${SRCS:.c=.o}

OBJSB		= ${B_SRCS:.c=.o}

NAME		= push_swap.a

CHECKER		= checker.a

CC			= gcc

CCFLAGS 	= -Wall -Werror -Wextra

INCLUDES	= -I./includes -I./libft

all:		${NAME}


${NAME}:	$(OBJS)
			$(MAKE) bonus -C ./libft
			cp ./libft/libft.a $(NAME)
			ar -r $(NAME) $(OBJS)
			gcc -o push_swap $(CCFLAGS) $(NAME)
			ranlib $(NAME)

bonus:		$(OBJSB)
			$(MAKE) bonus -C ./libft
			cp ./libft/libft.a $(CHECKER)
			ar -r $(CHECKER) $(OBJSB)
			gcc -o checker $(CCFLAGS) $(CHECKER)
			ranlib $(CHECKER)

clean:	
					$(MAKE) clean -C ./libft
					rm -f ${OBJS} ${OBJSB}

fclean:		clean
					$(MAKE) fclean -C ./libft
					rm -f ${NAME} ${CHECKER}

re:			fclean all

.PHONY:		all clean fclean re
