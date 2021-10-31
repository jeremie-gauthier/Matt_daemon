# https://stackoverflow.com/questions/2481269/how-to-make-a-simple-c-makefile

# built-in rules
CXX= clang++
CXXFLAGS= -Wall -Wextra -Werror

RM= rm -rf

DIR_SRC= src/
C_FILES_NAME= main

SRCS_C_FILES = $(addprefix $(DIR_SRC), $(C_FILES_NAME:=.cpp))
OBJS=$(subst .cpp,.o,$(SRCS_C_FILES))

NAME= Matt_daemon

.PHONY: all
all: $(NAME)

# implicitly apply CXXFLAGS
$(NAME): $(OBJS) Makefile
	$(CXX) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
