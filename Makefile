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

LIB_DIR =	.

MAKEFILES_DIR = $(LIB_DIR)/Makefiles

LIBS_MAKEFILES_DIR	=	$(MAKEFILES_DIR)/logger	\
						$(MAKEFILES_DIR)/linked_list	\

# ========== #
#  LIB NAME  #
# ========== #

NAME = library

# ======= #
#  RULES  #
# ======= #

all:	$(NAME)


$(NAME):
	@$(ECHO) $(MAGENTA) "===== ALL =====\n" $(DEFAULT)
	@$(foreach i, $(LIBS_MAKEFILES_DIR), $(ECHO) $(TEAL) "[INFO] Entering $(i):\n" $(DEFAULT); make -C $(i); )

debug:
	@$(ECHO) $(MAGENTA) "===== DEBUG =====\n" $(DEFAULT)
	@$(foreach i, $(LIBS_MAKEFILES_DIR), $(ECHO) $(TEAL) "[INFO] Entering $(i):\n" $(DEFAULT); make  debug -C $(i); )

clean:
	@$(ECHO) $(MAGENTA) "===== CLEAN RULE =====\n" $(DEFAULT)
	@$(foreach i, $(LIBS_MAKEFILES_DIR), $(ECHO) $(TEAL) "[INFO] Entering $(i):\n" $(DEFAULT); make clean -C $(i);)

fclean:	clean
	@$(ECHO) $(MAGENTA) "===== FCLEAN RULE =====\n" $(DEFAULT)
	@$(foreach i, $(LIBS_MAKEFILES_DIR), $(ECHO) $(TEAL) "[INFO] Entering $(i):\n" $(DEFAULT); make fclean -C $(i);)

re:	fclean all

.PHONY: $(NAME) clean fclean re