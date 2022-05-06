# COMMANDS
################################################################################
RM			= rm -f
CC			= c++

# SOURCES
################################################################################
SRCS		= all_tests.cpp
OBJS		= $(SRCS:.cpp=.o)

# EXECUTABLES & LIBRARIES
################################################################################
NAME		= tester

# DIRECTORIES
################################################################################
H1			= containers
H2			= iterators
H3			= utils
H4			= tests
HEADERS		= -I$(H1) -I$(H2) -I$(H3) -I$(H4)

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
.cpp.o:
			$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o) $(HEADERS)  

$(NAME):	$(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME) $(HEADERS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean .cpp.o re