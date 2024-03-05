CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

NAME_BONUS = checker

MAIN = main.c

SRCS =	cpy_node.c utils.c join.c \
		larger_sort.c leaks_free.c smaller_sort.c \
		split.c stack_list.c instructions.c \
		verify_args.c

SRCS_BNS =  checker_bonus.c get_next_line.c get_next_line_utils.c checker_utils_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_MAIN = ${MAIN:.c=.o}

OBJS_BNS = ${SRCS_BNS:.c=.o}

HEADERS = push_swap.h get_next_line.h checker_bonus.h

# .SILENT:

all: ${NAME}

bonus : ${NAME_BONUS}

%.o : %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${OBJS_MAIN} ${HEADER_MAIN}
		${CC} ${CFLAGS} ${OBJS_MAIN} ${OBJS} -o ${NAME}
		@echo "\033[1;32mProgram executed (./push_swap)\033[0m"


${NAME_BONUS} : ${NAME} ${OBJS_BNS} ${OBJS} ${HEADER_BNS}
		${CC} ${CFLAGS} ${OBJS_BNS} ${OBJS} -o ${NAME_BONUS}
		@echo "\033[1;32mChecker executed (./checker)\033[0m"

clean :
		@rm -rf ${OBJS} ${OBJS_BNS} ${OBJS_MAIN}

fclean : clean
		@rm -rf ${NAME} ${NAME_BONUS}

re : fclean all