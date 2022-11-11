
########## 		   NAMES 		##########

NAME = minishell

########## 		  SOURCES 		##########

SRC_PATH = ./src/

OBJ_DIR = objs

OBJ_PATH = $(OBJ_DIR)/

SRC = $(SRC_PATH)main.c	\
		$(SRC_PATH)cd_command.c	\
		$(SRC_PATH)echo_command.c	\
		$(SRC_PATH)env_command.c	\
		$(SRC_PATH)export_command.c	\
		$(SRC_PATH)pwd_command.c	\
		$(SRC_PATH)unset_command.c	\
		$(SRC_PATH)handle_ctrl.c	\
		$(SRC_PATH)execute.c		\
		$(SRC_PATH)command_info.c	\
		$(SRC_PATH)check_builtins.c	\
		$(SRC_PATH)error_msg.c		\
		$(SRC_PATH)parser.c

########## 		  INCLUDES 		##########

HEAD = ./inc

########## 		   LIBFT 		##########

LIBFT = libft

LIBFT_PATH = ./inc/libft/

########## 		COMPILATION 	##########

OBJ = $(patsubst %.c, %.o, $(subst $(SRC_PATH), $(OBJ_PATH), $(SRC)))

CC = gcc

########## 		   FLAGS 		##########

CFLAGS = -Wall -Wextra -Werror -g -lreadline

MLC_FLAGS = -fsanitize=address

########## 		   COLORS 		##########

GREEN		=	\033[0;32m
YELLOW	=	\033[0;33m
RED		=	\033[0;31m
BLUE_PISK		=	\033[0;34;5;199m
BLUE		=	\033[0;36m
VIOLET	=	\033[0;38;5;199m
RESET		=	\033[0m

########## 		  COMMANDS		##########

MAKE_LIBFT = cd ${LIBFT_PATH} && make all

CLEAN_LIBFT = cd ${LIBFT_PATH} && make clean

FCLEAN_LIBFT = cd ${LIBFT_PATH} && make fclean

RM = rm -rf

########## 		  MESSAGES 		##########

CREATE_PROJ_MSG = @echo "\n[ $(GREEN)$(NAME) created$(RESET) ]\n"

REMOVED_MSG = @echo "\n[ $(RED)$(NAME) removed$(RESET) ]\n"

NORM_LIBFT_MSG = @echo "\n[ $(YELLOW)Norm $(LIBFT)$(RESET) ]\n"

NORM_PROJ_MSG = @echo "\n[ $(YELLOW)Norm $(NAME)$(RESET) ]\n"

NORM_CORRECT = @echo "\nNorminette: [$(GREEN)OK$(RESET)]\n"

########## 		  TARGETS 		##########

${NAME}: ${OBJ_DIR} ${OBJ}
	${MAKE_LIBFT} -s
	$(CC) $(CFLAGS) $(MLC_FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(HEAD) -c $(^) -o $(@)
	@echo "$(YELLOW)[ Compiling $(subst .o,.c,$(notdir $@)) ]$(RESET)"

########## 		   RULES 		##########

all: ${NAME}
	${CREATE_PROJ_MSG}

clean:
	${CLEAN_LIBFT} -s
	${RM} ${OBJ_PATH}

fclean: clean
	${FCLEAN_LIBFT} -s
	${RM} ${NAME}
	${REMOVED_MSG}

re:	fclean all

norm:
	${NORM_LIBFT_MSG}
	@cd ${LIBFT_PATH} && make norm
	${NORM_PROJ_MSG}
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c
	@cd ./inc && norminette -R CheckDefine *.h
	${NORM_CORRECT}

.SILENT: ${OBJ} ${NAME} ${OBJ_DIR} clean fclean

.PHONY: all clean fclean re norm
