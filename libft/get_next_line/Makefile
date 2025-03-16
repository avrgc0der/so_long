NAME = get_next_line.a

SRCS =	get_next_line.c get_next_line_utils.c

REM = a.out

OBJS = $(SRCS:.c=.o)

BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -g3

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME) $(REM)

bonus : $(BONUS_OBJS)
	ar -rcs $(NAME) $(BONUS_OBJS)

re : fclean all

.PHONY : all clean fclean re bonus