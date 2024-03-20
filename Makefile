##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## SIUUUUUUUUUU look at this Makefile it work.
##
SRC = include/my_str_to_word_array.c \
	include/my_get_env.c \
	include/my_strtok_array.c \
	include/print_args.c \
	include/verif_exit.c \
	include/struct.c \
	include/my_command.c \
	include/unsetenv_setenv.c \
	include/play_command.c \
	include/my_errno.c \
	include/pipe.c \
	include/my_str_pipe_array.c \
	include/echo.c \

LIB =  lib/print.c \
	lib/my_strcat.c \
	lib/my_strncpy.c \
	lib/my_strncmp.c \
	lib/my_strcpy.c \
	lib/my_strcmp.c \
	lib/my_strdup.c \
	lib/my_skipstr.c \
	lib/walen.c \
	lib/wacpy.c

FILE_O = *.o
LIBMY_A = libmy.a
NAME = mysh


$(NAME):
	gcc -c $(SRC) -Iinclude
	gcc -g3 -o $(NAME) main.c $(SRC) $(LIB) -Iinclude
	make clean

clean:
	find -type f -iname '*.o' -delete
	find -type f -iname $(LIBMY_A) -delete

fclean:
	make clean
	find -type f -iname $(LIBMY_A) -delete
	rm -f $(NAME)

re:
	make fclean
	make
