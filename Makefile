# COMMANDS
################################################################################
RM			= rm -f
CC			= c++

# SOURCES
################################################################################
SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)

# EXECUTABLES & LIBRARIES
################################################################################
NAME		= 42tester

# DIRECTORIES
################################################################################
HEADERS		= -Isrcs/containers -Isrcs/iterators -Isrcs/utils

# FLAGS
################################################################################
CPPFLAGS		:= -Wall -Wextra -Werror -Wno-conversion -std=c++98 -pedantic

ifeq ($(DEBUG), true)
	CPPFLAGS	+= -fsanitize=address -g3 -O0
endif

ifeq ($(SILENT), true)
	CPPFLAGS	+= -DSILENCE
endif

# RULES
################################################################################
.c.o:
			$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o) -I$(HEADERS)

$(NAME):	$(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean c.o re