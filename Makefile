NAME = server
NAME2 = client

BONUS = server_bonus
BONUS2 = client_bonus

CC = clang
CFLAGS = -Werror -Wall -Wextra -g

SERVER_SRCS = server.c
CLIENT_SRCS = client.c
SERVER_SRCS_B = server_bonus.c utils_bonus.c
CLIENT_SRCS_B = client_bonus.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS_B = $(CLIENT_SRCS_B:.c=.o)
SERVER_OBJS_B = $(SERVER_SRCS_B:.c=.o)

INCLUDE = minitalk.h
INCLUDE_B = minitalk_bonus.h

all: $(NAME) $(NAME2) $(INCLUDE)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SERVER_OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SERVER_OBJS)
	@echo "\nCompile SERVER.........................\033[32m[DONE]\033[0m"

$(NAME2): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) -o $(NAME2) $(CLIENT_OBJS)
	@echo "Compile CLIENT.........................\033[32m[DONE]\033[0m\n"
	@echo "\033[34m __  __ ___ _   _ ___ _____  _    _     _  __\033[0m"
	@echo "\033[34m|  \/  |_ _| \ | |_ _|_   _|/ \  | |   | |/ /\033[0m"
	@echo "\033[34m| |\/| || ||  \| || |  | | / _ \ | |   | ' /\033[0m"
	@echo "\033[34m| |  | || || |\  || |  | |/ ___ \| |___| . \ \033[0m"
	@echo "\033[34m|_|  |_|___|_| \_|___| |_/_/   \_\_____|_|\_\ \033[0m\n"
	@echo "\033[35m==============================================\033[0m\n"
	@echo "\033[33m              First run ./server\033[0m\n"
	@echo "\033[33m       Then ./client in another terminal\033[0m\n"
	@echo "\033[35m==============================================\033[0m\n"


bonus: $(BONUS) $(BONUS2)

$(BONUS): $(SERVER_OBJS_B)
	@$(CC) $(CFLAGS) -o $(NAME) $(SERVER_OBJS_B)
	@echo "\nCompile SERVER.........................\033[32m[DONE]\033[0m"

$(BONUS2): $(CLIENT_OBJS_B)
	@$(CC) $(CFLAGS) -o $(NAME2) $(CLIENT_OBJS_B)
	@echo "Compile CLIENT.........................\033[32m[DONE]\033[0m\n"
	@echo "\033[34m __  __ ___ _   _ ___ _____  _    _     _  __\033[0m"
	@echo "\033[34m|  \/  |_ _| \ | |_ _|_   _|/ \  | |   | |/ /\033[0m"
	@echo "\033[34m| |\/| || ||  \| || |  | | / _ \ | |   | ' /\033[0m"
	@echo "\033[34m| |  | || || |\  || |  | |/ ___ \| |___| . \ \033[0m"
	@echo "\033[34m|_|  |_|___|_| \_|___| |_/_/   \_\_____|_|\_\ \033[0m"
	@echo "\033[36m                                        BONUS\033[0m\n"
	@echo "\033[35m==============================================\033[0m\n"
	@echo "\033[33m              First run ./server\033[0m\n"
	@echo "\033[33m       Then ./client in another terminal\033[0m\n"
	@echo "\033[35m==============================================\033[0m\n"

clean:
	@${RM} ${SERVER_OBJS}
	@${RM} ${CLIENT_OBJS}
	@${RM} ${SERVER_OBJS_B}
	@${RM} ${CLIENT_OBJS_B}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${NAME2}
	@${RM} ${BONUS}
	@${RM} ${BONUS2}

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
