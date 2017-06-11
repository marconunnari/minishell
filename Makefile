# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/09 14:31:16 by mnunnari          #+#    #+#              #
#    Updated: 2017/06/11 05:55:30 by mnunnari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell
GCC=gcc -Wall -Wextra -Werror
INCLUDES= -Iincludes -Ilibft/includes
LIBFT=libft/libft.a
LFT= -Llibft -lft
DOBJS= objs
DSRCS= srcs
HEADER=includes/minishell.h

SRCS_FILES= main parsecmd get_next_tok run_prog builtin ms_find_prog \
			ms_echo ms_setenv ms_unsetenv ms_env ms_cd \
			get_envar print_env set_envar #new#

SRCS = $(addprefix $(DSRCS)/, $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(SRCS:$(DSRCS)/%.c=$(DOBJS)/%.o)

all: $(NAME)

$(DOBJS):
	mkdir -p $(DOBJS)

dolibft:
	make -C libft

$(OBJS): $(DOBJS)/%.o: $(DSRCS)/%.c $(HEADER)
	$(GCC) $(INCLUDES) -c $< -o $@

$(NAME): dolibft $(DOBJS) $(OBJS) $(HEADER)
	$(GCC) -o $(NAME) $(OBJS) $(LFT)

clean:
	make clean -C libft
	rm -rf $(DOBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
