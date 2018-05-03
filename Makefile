# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2018/01/15 14:29:46 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	prippa.filler
VISU			=	visualizer

#FLAGS		= 	-Wall -Werror -Wextra

CC				=	gcc -g

DIR_LIB			=	./libft/
LIBFT			=	$(DIR_LIB)libft.a
DIR_INC			=	$(DIR_LIB)includes/
DIR_FIL_INC		=	./includes/
DIR_FIL			=	./filler_src/
DIR_VIS			=	./visualizer_src/
DIR_SRC			=	./source/
DIR_OBJ			= 	./obj/
DIR_VIS_OBJ		= 	./vis_obj/

HEAD_LIBFT		=	libft.h
HEAD_FPF		=	ft_printf.h
HEAD_FIL		=	filler.h
HEAD_VIS		=	vis.h

C_FIL			=	main.c fi_algorithm.c fi_point_list.c\
				fi_get_board.c fi_get_figur.c\
				fi_get_points.c

C_VIS			=	main.c vis_start_entry.c\
				vis_game.c vis_helpers.c vis_end.c

C_SRC			=	fi_get_y_x.c

OBJ_FILLER 		= 	$(C_FIL:.c=.o)
OBJ_VISUALIZE 	= 	$(C_VIS:.c=.o)
OBJ_SOURCE 		= 	$(C_SRC:.c=.o)

OBJ_FIL 		= 	$(addprefix $(DIR_OBJ), $(OBJ_FILLER) $(OBJ_SOURCE))
OBJ_VIS 		= 	$(addprefix $(DIR_VIS_OBJ), $(OBJ_VISUALIZE) $(OBJ_SOURCE))
INC_LIB 		= 	$(addprefix -I, $(DIR_INC) $(DIR_FIL_INC))
INC_FIL 		= 	$(addprefix $(DIR_FIL_INC), $(HEAD_FIL))
INC_VIS 		= 	$(addprefix $(DIR_FIL_INC), $(HEAD_VIS))


all: lib obj $(NAME) $(VISU)

lib:
	@make -C $(DIR_LIB)
	
obj:
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(DIR_VIS_OBJ)

#-----------FILLER------------------------------------
$(NAME): $(OBJ_FIL) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ_FIL) $(LIBFT)
	@echo "Compiling" [ $(NAME) ]
	mv $(NAME) ./players/ #<------------------------------REMOVE

$(DIR_OBJ)%.o: $(DIR_FIL)%.c $(INC_FIL)
	@$(CC) $(FLAGS) $(INC_LIB) -c -o $@ $<
	@echo "Linking" [ $< ]

$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC_FIL)
	@$(CC) $(FLAGS) $(INC_LIB) -c -o $@ $<
	@echo "Linking" [ $< ]
#-----------------------------------------------------

#-----------VISUALIZER--------------------------------
$(VISU): $(OBJ_VIS) $(LIBFT)
	@$(CC) -o $(VISU) $(OBJ_VIS) $(LIBFT)
	@echo "Compiling" [ $(VISU) ]

$(DIR_VIS_OBJ)%.o: $(DIR_VIS)%.c $(INC_VIS)
	@$(CC) $(FLAGS) $(INC_LIB) -c -o $@ $<
	@echo "Linking" [ $< ]

$(DIR_VIS_OBJ)%.o: $(DIR_SRC)%.c $(INC_VIS)
	@$(CC) $(FLAGS) $(INC_LIB) -c -o $@ $<
	@echo "Linking" [ $< ]
#-----------------------------------------------------

clean:
	@rm -rf $(DIR_OBJ)
	@rm -rf $(DIR_VIS_OBJ)
	@echo "Clean [ obj files filler ]"
	@echo "Clean [ obj files visualizer ]"
	@make -C $(DIR_LIB) clean

fclean:
	@rm -rf $(DIR_OBJ)
	@rm -rf $(DIR_VIS_OBJ)
	@echo "Clean [ obj files filler ]"
	@echo "Clean [ obj files visualizer ]"
	@rm -f $(NAME)
	@rm -f $(VISU)
	@echo "Clean" [ $(NAME) ]
	@echo "Clean" [ $(VISU) ]
	@make -C $(DIR_LIB) fclean

re: fclean all

.PHONY: all clean fclean re
