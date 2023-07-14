NAME = so_long
LIBFTDIR = ./libft
FILES = so_long.c path_verify.c map_verifiers.c other_utils.c images_manage.c movement.c map_utils.c
OBJS = $(FILES:.c=.o)

FLAGS =  -Wall -Werror -Wextra 
MINIFLAGS = -lmlx -framework OpenGL -framework Appkit
RM = rm -fr
AR = ar r
DIR = .


.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	@make -C $(LIBFTDIR)
	@cp libft/libft.a $(NAME)
	gcc $(FLAGS) -o so_long $(OBJS) -L$(LIBFTDIR) -lft $(MINIFLAGS)
all: $(NAME)
clean:
	@make clean -C $(LIBFTDIR)
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	@make fclean -C $(LIBFTDIR)
	$(RM) $(NAME)
re: fclean all
$(DIR): $(OBJS)
	${AR} $(NAME) $(OBJS)
.PHONY: all clean fclean re bonus
