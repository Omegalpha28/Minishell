##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## SIUUUUUUUUUU look at this Makefile it work.
##

LIB :=  lib/my_strlen.c \
	lib/my_stowa.c \
	lib/my_putchar.c \
	lib/my_putstr.c \
	lib/my_numlen.c \
	lib/my_put_nbr.c \
	lib/my_strcat.c \
	lib/my_strcpy.c \
	lib/my_strcmp.c \
	lib/my_strdup.c \
	lib/my_skipstr.c

SRC :=	$(LIB) \
	include/my_get_env.c \
	include/my_strtok_array.c \
	include/print_args.c \
	include/verif_exit.c \
	include/struct.c \
	include/my_command.c \
	include/unsetenv_setenv.c \
	include/play_command.c \
	include/my_errno.c \
	include/add_pipe.c \
	include/my_str_pipe_array.c \
	include/echo.c \
	include/verif_option.c \
	include/my_char_is_alphanum.c \
	include/walen.c \
	include/wacpy.c \
	include/my_strncpy.c \
	include/my_strncmp.c

FILE_O = *.o
LIBMY_A = libmy.a
NAME = mysh
TLIB = -lcriterion --coverage
TEST = test/unit/*.c
TSRC := $(LIB)
W := -Wall -Wextra -Iinclude

$(NAME):
	gcc -c $(SRC) -Iinclude
	gcc -g3 -o $(NAME) main.c $(SRC) $(W) -g3
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

tests_build:
	gcc -o unit_tests $(TSRC) $(TEST) $(TLIB)

tests_run: tests_build
	find -type f -iname "*.gcno" -delete
	find -type f -iname "*.gcda" -delete
	find -type f -iname "*.css" -delete
	find -type f -iname "*.html" -delete
	./unit_tests

tests_clean:
	find -type f -iname "*.gcno" -delete
	find -type f -iname "*.gcda" -delete
	find -type f -iname "*.css" -delete
	find -type f -iname "*.html" -delete

tests_fclean: tests_clean
	rm -f unit_tests

tests_re: tests_fclean tests_run
