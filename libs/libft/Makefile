NAME = libft.a

RAW_SRCS= $(shell find .)
SRCS = $(filter %.c, $(RAW_SRCS))
OBJS = $(SRCS:.c=.o)

COMPILER = cc -Wall -Wextra -Werror -I ./includes

.c.o:
	@ $(COMPILER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	@ ar rc $(NAME) $(OBJS)
	@ echo "✅ libft compile complete!\n"

clean:
	@ rm -f $(OBJS)
	@ echo "🧹 libft clean complete!\n"

fclean:	clean
	@rm -f $(NAME)
	@ echo "🧹 libft fclean complete!\n"

re: clean fclean $(NAME)
	@ echo "🔄 libft re complete!\n"


