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
NAME		= tester

# DIRECTORIES
################################################################################
HEADERS		= containers

# FLAGS
################################################################################
CPPFLAGS		+= -Wall -Wextra -Werror -std=c++98 -pedantic

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