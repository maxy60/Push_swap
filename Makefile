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
			  mediane.c				\

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap.a

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
clean:	
					$(MAKE) clean -C ./libft
					rm -f ${OBJS}

fclean:		clean
					$(MAKE) fclean -C ./libft
					rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
