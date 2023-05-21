
NAME = fdf
SRC = fdf_mandatory.c calcul_x_y.c get_next_line.c get_next_line_utils.c map_utils_1.c	some_libft_func_part_1.c	some_libft_func_part_2.c drawing_lines.c draw_lines_utils.c map_utils_2.c map_utils.c fdf_mandatory_utils.c	fdf_mandatory_utils_1.c
SRC_BONUS = draw_lines_utils.c	calcul_x_y.c	controlling_win_utils.c	controlling_win.c	drawing_lines.c	fdf_utils.c	fdf_bonus.c	get_next_line.c	get_next_line_utils.c	map_utils_1.c	map_utils_2.c	map_utils_3.c	map_utils.c	some_libft_func_part_1.c	some_libft_func_part_2.c
MLXFRAME = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
R        := $(shell tput -Txterm setaf 1)
G        := $(shell tput -Txterm setaf 2)
Y       := $(shell tput -Txterm setaf 3)

all: $(NAME)
	@echo $(G) "ALL functions are done!"

$(NAME): $(OBJS)
	@echo $(Y) Compiling: $< ... Done!
	@cc $(CFLAGS) $(MLXFRAME) $(OBJS) -o $@

%.o: %.c fdf.h get_next_line.h
	@echo $(Y) Compiling: $< ... Done!
	@cc $(CFLAGS) -c $<

bonus: ${OBJS_BONUS}
	@echo $(Y) Compiling: $< ... Done!
	@cc $(CFLAGS) $(MLXFRAME) $(OBJS_BONUS) -o $(NAME)

clean:
	@echo $(R) Cleaned
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo $(R) Fully cleaned
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus all