##
## C_Linked-List_Lib PROJECT, 2020
## Makefile
## File description:
## Global Makefile for any kind of C project
## This one will compile a Linux executable.
## Contains rules : all, debug, clean, fclean, re
##

# ============================== #
#   Author : Alexandre Calvet    #
# https://github.com/calvetalex/ #
# ============================== #

# =============== #
#  COLOR & SHELL  #
# =============== #

DEFAULT		=	"\033[00m"
GREEN		=	"\033[1;32m"
TEAL		=	"\033[1;36m"
YELLOW		=	"\033[1;184m"
MAGENTA		=	"\033[1;95m"
ERROR		=	"\033[5;7;1;31m"
ERRORMSG	=	"\033[1;7;31m"

ECHO	=	echo -e

RM		=	rm -rf

# =========== #
#  VARIABLES  #
# =========== #

LIB_DIR =	../..

OUTPUT_DIR = $(LIB_DIR)/output

SRC_DIR = 	$(LIB_DIR)/src/logger

SRC	=	$(SRC_DIR)/manager.c	\
		$(SRC_DIR)/print.c	\

# ======= #
#  FLAGS  #
# ======= #

cflags.common	:=	-W -Wall -Wextra -Wno-unused-variable -pedantic -D_GNU_SOURCE -I$(LIB_DIR)/include/logger
cflags.debug	:=	-g -g3
cflags.release	:=
cflags.tests	:=

CFLAGS	:=	${cflags.release} ${cflags.common}

# ========= #
#  OBJECTS  #
# ========= #

OBJ	=	$(SRC:.c=.o)

# ========== #
#  LIB NAME  #
# ========== #

NAME	=	log

# ======= #
#  RULES  #
# ======= #

all:	$(NAME)

%.o	:	%.c
		@$(CC) -c $< -o $@ $(CFLAGS) && \
		$(ECHO) $(GREEN) "[OBJ] " $(TEAL) $@ "\thas been created from\t" $@ $(DEFAULT) || \
		$(ECHO) $(ERROR) " [ERROR] " $(ERRORMSG) " can't find " $^ $(DEFAULT)


$(NAME):	$(OBJ)
	@ar rc $(OUTPUT_DIR)/lib$(NAME).a $(OBJ)&& \
	( $(ECHO) $(GREEN) "["$@"] lib is ready. To use it with gcc use -L and -l options." $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(ERRORMSG) lib$(NAME).a $(DEFAULT) )

clean:
	@$(foreach i, $(OBJ), $(shell rm -rf $(i)) echo -e $(MAGENTA) "Deleting...\t\t$(i)" $(DEFAULT);)
	@$(RM) *~ && \
	$(ECHO) $(GREEN) "[OK] clean rule success msg" $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(ERRORMSG) lib$(NAME).a $(DEFAULT)

fclean:	clean
	@rm -f $(OUTPUT_DIR)/lib$(NAME).a && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)" clean done and lib removed." $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(ERRORMSG) libm$(BINNAME).a $(DEFAULT)

re:	fclean all

.PHONY: $(NAME) clean fclean re