NAME		=	so_long
	
SRCS		=
	
CC			=	clang
	
CFFLAGS		=	-Wall -Wextra -Werror -g3

INCLUDES	=	-I. -Iminilibx-linux/. 

LIB			=	-Lminilibx-linux -lmlx -lXext -lX11 -Llibft -lft 

OBJS		=	$(SRCS:%.c=%.o)

all	:	$(NAME)

%.o	:	%.c
	$(CC) $(CFFLAGS) $(INCLUDES) -c $< -o $@

$(NAME)	:	$(OBJS)
	make -C minilibx-linux
	make -C libft
	$(CC) $(CFFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

clean :
	rm -rf $(OBJS)
	make -C minilibx-linux clean
	make -C libft clean

fclean : clean
	rm -rf $(NAME)
	make -C libft fclean

re : fclean all

.PHONY: all clean fclean re
