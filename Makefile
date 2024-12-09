NAME = so_long.a

SRCS =

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME} build

build :
	@echo "$(YELLOW)/\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\$(RESET)"
	@echo "$(CYAN)( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )"
	@echo "$(MAGENTA) > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ < "
	@echo "$(WHITE) /\_/\    █████▒▄▄▄█████▓ ██▓███   ██▀███   ██▓ ███▄    █ ▄▄▄█████▓  █████▒   /\_/\ "
	@echo "$(RED)( o.o ) ▓██   ▒ ▓  ██▒ ▓▒▓██░  ██▒▓██ ▒ ██▒▓██▒ ██ ▀█   █ ▓  ██▒ ▓▒▓██   ▒   ( o.o )"
	@echo "$(GREEN) /\_/\  ░▓█▒  ░ ░ ▓██▓ ░ ▒██▄█▓▒ ▒▒██▀▀█▄  ░██░▓██▒  ▐▌██▒░ ▓██▓ ░ ░▓█▒  ░    /\_/\ "
	@echo "$(BLUE)( o.o ) ░▒█░      ▒██▒ ░ ▒██▒ ░  ░░██▓ ▒██▒░██░▒██░   ▓██░  ▒██▒ ░ ░▒█░      ( o.o )"
	@echo "$(RED) > ^ <   ▒ ░      ▒ ░░   ▒▓▒░ ░  ░░ ▒▓ ░▒▓░░▓  ░ ▒░   ▒ ▒   ▒ ░░    ▒ ░       > ^ < "
	@echo "$(GREEN) /\_/\   ░          ░    ░▒ ░       ░▒ ░ ▒░ ▒ ░░ ░░   ░ ▒░    ░     ░         /\_/\ "
	@echo "$(BLUE)( o.o )  ░ ░      ░      ░░         ░░   ░  ▒ ░   ░   ░ ░   ░       ░ ░      ( o.o )"
	@echo "$(WHITE) > ^ <                               ░      ░           ░                     > ^ < "
	@echo "$(MAGENTA) /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\ "
	@echo "$(CYAN)( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )"
	@echo "$(YELLOW) > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ < "

RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
RESET=\033[0m

${NAME} : ${OBJS}
	ar rcs $@ $^

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME} 

re : fclean all

.PHONY : all clean fclean re