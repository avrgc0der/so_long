NAME = libft.a

SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isalnum.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c \
		ft_strchr.c ft_strdup.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strnstr.c ft_strrchr.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_memcpy.c ft_memset.c \
		ft_strncmp.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strmapi.c \
		ft_striteri.c ft_substr.c ft_split.c ft_itoa.c ft_strtrim.c\

REM = a.out

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstadd_front.c ft_lstnew.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap->c

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