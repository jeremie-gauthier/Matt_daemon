# https://stackoverflow.com/questions/2481269/how-to-make-a-simple-c-makefile

DIR_SRC= src/
DIR_HEADERS= headers/

# built-in rules
CXX= clang++
CXXFLAGS= -Wall -Wextra -Werror -I $(DIR_HEADERS) 

RM= rm -rf

SRCS_RAW= main

SRCS = $(addprefix $(DIR_SRC), $(SRCS_RAW:=.cpp))
OBJS=$(subst .cpp,.o,$(SRCS))

HEADERS_RAW= $(BASE)
HEADERS=$(addprefix $(DIR_HEADERS), $(HEADERS_RAW:=.hpp))

NAME= Matt_daemon

.PHONY: all
all: $(NAME)

# implicitly apply CXXFLAGS
$(NAME): $(OBJS) $(HEADERS) Makefile
	$(CXX) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
