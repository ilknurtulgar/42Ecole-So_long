NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS= ft_strdup.c \
		ft_strlen.c \
		ft_memset.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_strchr.c\
		ft_itoa.c\

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean: 
	$(RM) $(OBJ) 
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 