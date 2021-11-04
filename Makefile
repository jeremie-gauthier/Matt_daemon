# https://stackoverflow.com/questions/2481269/how-to-make-a-simple-c-makefile

DIR_SRC= src/
DIR_HEADERS= includes/

# built-in rules
CXX= clang++
CXXFLAGS= -Wall -Wextra -Werror -std=c++11 -I $(DIR_HEADERS) 

RM= rm -rf

SRCS_RAW= main\
					daemon\
					Tintin_reporter.class\
					Listener.class\

SRCS = $(addprefix $(DIR_SRC), $(SRCS_RAW:=.cpp))
OBJS=$(subst .cpp,.o,$(SRCS))

HEADERS_RAW=	common\
							daemon\
							Tintin_reporter.class\
							Listener.class\

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
