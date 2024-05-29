NAME= so_long
SRCS= main.c \
	  start_check_1.c \
	  start_check_2.c \
	  game_info_1.c\
	  game_info_2.c\
	  map_check_1.c\
	  graphics.c\
	  map_move_1.c\
	  map_move_2.c\
	  read_map.c\
	  gnl/get_next_line.c\
	  gnl/get_next_line_utils.c\
	  map_check_2.c\
	  map_check_3.c\

OBJS=$(SRCS:.c=.o)

CC=gcc
CFLAGS= -Wall -Wextra -Werror -g
RM= rm -rf
PRINTF=./ft_printf/libftprintf.a 
LIBFT= ./libft/libft.a 
MLX=./mlx/libmlx.a
LDFLAGS = -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit
PINK=\033[0;35m
NC=\033[0m

all: $(NAME)

$(NAME) : $(OBJS)
	make -C ./ft_printf -s
	make -C ./libft -s
	make -C ./mlx 2>/dev/null
	$(CC) $(CFLAGS) $(OBJS)  $(PRINTF) $(LIBFT)  $(MLX)  $(LDFLAGS) -o $(NAME)
	@echo "$(PINK)<< THE GAME İS READY! <3 >>$(NC)"

clean: 
	make clean -C ./ft_printf -s
	make clean -C ./libft -s
	$(RM) $(OBJS)
	@echo "$(PINK)<< OBJECTS FİLE İS REMOVED! <3 >>$(NC)"

fclean: clean
	make fclean -C ./ft_printf -s
	make fclean -C ./libft -s
	make clean -C ./mlx -s
	$(RM) $(NAME)
	@echo "$(PINK)<< THE GAME İS REMOVED! <3 >>$(NC)"

re: fclean all

.PHONY:all clean fclean re