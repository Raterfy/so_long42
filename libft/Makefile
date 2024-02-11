NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

INCLUDES = -I includes/

SRCS = sources/conv/ft_atoi.c \
	sources/conv/ft_itoa.c \
	sources/ctypes/ft_isalnum.c \
	sources/ctypes/ft_isalpha.c \
	sources/ctypes/ft_isascii.c \
	sources/ctypes/ft_isdigit.c \
	sources/ctypes/ft_isprint.c \
	sources/ctypes/ft_tolower.c \
	sources/ctypes/ft_toupper.c \
	sources/ctypes/ft_isspace.c \
	sources/io/get_next_line.c \
	sources/io/get_next_line_utils.c \
	sources/io/printf/ft_printf.c \
	sources/io/printf/printf_conversion.c \
	sources/io/printf/printf_conversion2.c \
	sources/io/printf/printf_function.c \
	sources/io/ft_putchar_fd.c \
	sources/io/ft_putendl_fd.c \
	sources/io/ft_putnbr_fd.c \
	sources/io/ft_putstr_fd.c \
	sources/lists/ft_lstadd_back.c \
	sources/lists/ft_lstadd_front.c \
	sources/lists/ft_lstclear.c \
	sources/lists/ft_lstdelone.c \
	sources/lists/ft_lstiter.c \
	sources/lists/ft_lstlast.c \
	sources/lists/ft_lstmap.c \
	sources/lists/ft_lstnew.c \
	sources/lists/ft_lstsize.c \
	sources/memory/ft_bzero.c \
	sources/memory/ft_calloc.c \
	sources/memory/ft_memchr.c \
	sources/memory/ft_memcmp.c \
	sources/memory/ft_memcpy.c \
	sources/memory/ft_memmove.c \
	sources/memory/ft_memset.c \
	sources/strings/ft_split.c \
	sources/strings/ft_strchr.c \
	sources/strings/ft_strdup.c \
	sources/strings/ft_striteri.c \
	sources/strings/ft_strjoin.c \
	sources/strings/ft_strlcat.c \
	sources/strings/ft_strlcpy.c \
	sources/strings/ft_strlen.c \
	sources/strings/ft_strmapi.c \
	sources/strings/ft_strncmp.c \
	sources/strings/ft_strnstr.c \
	sources/strings/ft_strrchr.c \
	sources/strings/ft_strtrim.c \
	sources/strings/ft_substr.c \

HDR = includes/ft_printf.h \
	includes/get_next_line.h \
	includes/libft.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HDR)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#so:
#	cc -Wall -Wextra -Werror -fPIC $(SRCS) $(BNS_SRCS) -shared -o libft.so -nostartfiles
