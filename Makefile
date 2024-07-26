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
	@echo "\n$(BGreen)*** Building target file: $(NAME) ***\n"
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "$(BGreen)EAT 🍽️   SLEEP 😴   THINK 🤔  or  DIE 💀\n$(NC)"
	@echo "Input: (1)num_philos (2)time_until_death (3)time_to_eat (4)time_to_sleep (5)max_meals"

BGreen=\033[1;32m
BBlue=\033[1;34m
NC =\033[0m

all : $(NAME)

fclean : clean
	@$(RM) $(NAME)

clean :
	@echo "\n$(BBlue)Cleaning......"
	@$(RM) $(NAME)
	@echo "............ READY\n"

re : fclean all
	@echo "$(BGreen)Program successfully recompiled$(NC)"

.PHONY: all clean fclean re