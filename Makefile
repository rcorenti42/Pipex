NAME = Pipex

CC = gcc

FLAGS = -g -I $(HEADER)

LIBFT = libft/libft.a

HEADER =	includes

srcs =		pipex.c \

OBJS = ${addprefix srcs/,${srcs:.c=.o}}

.c.o :
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME) :	${OBJS} ${LIBFT} ${HEADER}
			${CC} ${FLAGS} ${OBJS} -o ${NAME} ${LIBFT}

$(LIBFT) :
			make -C ./libft

all :		${NAME}

clean :
			make clean -C libft
			rm -rf ${OBJS}
			rm -rf ${LIBFT}

fclean :	clean
			@rm -rf ${NAME}

re :		fclean all

.PHONY :	all clean fclean re