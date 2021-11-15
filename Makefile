NAME = pipex

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = includes

LIBFT = libft/libft.a

srcs = pipex.c

OBJS = ${addprefix srcs/,${srcs:.c=.o}}

.c.o :
	${CC} ${FLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) ${LIBFT} ${HEADER}
	${CC} ${FLAGS} ${OBJS} -o ${NAME} ${LIBFT}

$(LIBFT):
	make -C ./libft

clean:
	@rm -f $(OBJS)
	@rm -rf $(LIBFT)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)

re: fclean all
