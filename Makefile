##
## Makefile for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/
##
## Made by Laurent Coloma
## Login   <laurent.coloma@epitech.eu>
##
## Started on  Thu Apr 27 16:42:50 2017 Laurent Coloma
## Last update Thu May 18 13:24:36 2017 Laurent Coloma
##

CC						=						gcc

CFLAGS				=						-W -Wall -Wextra -I./include -g -g3

SRCS					=						main.c											\
													src/is_exec.c								\
													src/my_exec.c								\
													src/my_getenv.c							\
													src/mysh.c									\
													src/aux/getnextline.c				\
													src/aux/is_alphanum.c				\
													src/aux/my_getnbr.c					\
													src/aux/my_putchar.c				\
													src/aux/my_putstr.c					\
													src/aux/my_str_to_wordtab.c	\
													src/aux/my_strcat_path.c		\
													src/aux/my_strcat.c					\
													src/aux/my_strdup.c					\
													src/aux/my_strlen.c					\
													src/aux/my_strncmp.c				\
													src/builtin/my_cd.c					\
													src/builtin/my_echo.c				\
													src/builtin/my_env.c				\
													src/builtin/my_exit.c				\
													src/builtin/my_setenv.c			\
													src/builtin/my_unsetenv.c

OBJS					=						$(SRCS:.c=.o)

NAME					=						mysh

all: $(NAME)

$(NAME): $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
					rm -f $(OBJS)

fclean: clean
					rm -f $(NAME)

re: fclean all
