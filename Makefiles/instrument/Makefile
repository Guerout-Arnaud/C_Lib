##
## C_Lib PROJECT, 2020
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

ECHO	=	echo

RM		=	rm -rf

# =========== #
#  VARIABLES  #
# =========== #

LIB_DIR =	../..

OUTPUT_DIR = $(LIB_DIR)/output

TEST_DIR = $(LIB_DIR)/tests/instrument

SRC_DIR = 	$(LIB_DIR)/src/instrument

SRC = ${SRC_DIR}/utils.c

SRC_PERF	=	$(SRC_DIR)/performance.c	\
				$(TEST_DIR)/performance_test.c

# ======= #
#  FLAGS  #
# ======= #

cflags.common	:=	-W -Wall -Wextra -pedantic -no-pie -finstrument-functions -I$(LIB_DIR)/include/

ldflags.common	:=	-L${OUTPUT_DIR} -llinked_list

CFLAGS	:= ${cflags.common}
LDFLAGS	:= ${ldflags.common}



# ========= #
#  OBJECTS  #
# ========= #

OBJ	=	$(SRC:.c=.o)

OBJ_PERF	=	$(SRC_PERF:.c=.o)

# ========== #
#  LIB NAME  #
# ========== #

NAME	=	instrument

# ======= #
#  RULES  #
# ======= #

all:	help

help : 
	@$(ECHO) ${YELLOW} "THIS PART OF THE LIB DOES NOT CREATE .a FILE. Read README.md file for more infos."

%.o	:	%.c
		@$(CC) -c $< -o $@ $(CFLAGS) && \
		$(ECHO) "[OBJ] $< \thas been created from\t" $@  || \
		$(ECHO) " [ERROR]  can't find " $^ 

set_performance:
	$(eval SRC=${SRC} $(SRC_DIR)/performance.c $(TEST_DIR)/performance.c)

performance	:	$(OBJ) $(OBJ_PERF)
			@make -s -C ../linked_list
			@$(CC) -o ${OUTPUT_DIR}/$(NAME)_performance $(OBJ) $(OBJ_PERF) $(CFLAGS) $(LDFLAGS)

clean:
	$(eval RM_OBJ=${OBJ} ${OBJ_PERF})
	@$(foreach i, ${RM_OBJ}, $(shell rm -rf $(i)) echo -e $(MAGENTA) "Deleting...\t\t$(i)" $(DEFAULT);)
	@$(RM) *~ && \
	$(ECHO) $(GREEN) "[OK] clean rule success msg" $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(ERRORMSG) lib$(NAME).a $(DEFAULT)

fclean:	clean
	@rm -f $(OUTPUT_DIR)/lib$(NAME).a && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)" clean done and lib removed." $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(ERRORMSG) lib$(NAME).a $(DEFAULT)

re:	fclean all

.PHONY: $(NAME) clean fclean re