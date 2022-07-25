# COMMANDS
################################################################################
RM			= rm -f
RMRF		= rm -rf
CC			= c++
CD			= cd
MKDIR		= mkdir
GCLONE		= git clone

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
LIBRARIES	= lib
BUILD		= build

# FLAGS
################################################################################
CPPFLAGS		:= -Wall -Wextra -Werror -Wno-conversion -std=c++98

ifeq ($(DEBUG), true)
	CPPFLAGS	+= -fsanitize=address -g3 -O0
endif

ifeq ($(SILENT), true)
	CPPFLAGS	+= -DSILENCE
endif

# RULES
################################################################################
.cpp.o:
			$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o) -I$(HEADERS)

$(NAME):	$(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(RMRF) $(LIBRARIES)
			$(RMRF) $(BUILD)

fclean:		clean
			$(RM) $(NAME)


test:		clean
			$(MKDIR) $(LIBRARIES) && $(CD) $(LIBRARIES) && \
			$(GCLONE) git@github.com:google/googletest.git
			$(MKDIR) $(BUILD) && $(CD) $(BUILD) && \
			cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
			make all -C build

re:			fclean all

.PHONY:		all clean fclean c.o re
