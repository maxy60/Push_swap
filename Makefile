SRCS		= ft_stack.c		\
			  main.c			\
			  ft_instruction.c	\
			  push_swap.c		\

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
