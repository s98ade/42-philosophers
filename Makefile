NAME = philo  

RM = rm -f

CC = gcc

SRCS = $(addprefix ./src/, main.c \
						   utils1.c \
						   utils2.c \
						   monitor.c \
						   routine.c \
						   threads.c \
						   init_data.c)

HEADER = -I ./includes

CFLAGS = -g -Wall -Wextra -Werror -pthread $(HEADER)

$(NAME) :
	@echo "\n$(BGreen)Building target file: $(NAME)"
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "$(BGreen)EAT 🍽️   SLEEP 😴   THINK 🤔  or  DIE 💀"

BGreen=\033[1;32m
BBlue=\033[1;34m
NC =\033[0m

all : $(NAME)

fclean : clean
	@$(RM) $(NAME)

clean :
	@echo "$(BBlue)Cleaning......"
	@$(RM) $(NAME)
	@echo "............ READY"

re : fclean all
	@echo "$(BGreen)Program successfully recompiled$(NC)"

.PHONY: all clean fclean re