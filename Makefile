NAME=minishell
GCC=gcc -Wall -Wextra -Werror
INCLUDES= -Iincludes -Ilibft/includes
LIBFT=libft/libft.a
LFT= -Llibft -lft
DOBJS= objs
DSRCS= srcs
HEADER=includes/minishell.h

SRCS_FILES= main #new#

SRCS = $(addprefix $(DSRCS)/, $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(SRCS:$(DSRCS)/%.c=$(DOBJS)/%.o)

all: $(NAME)

$(DOBJS):
	mkdir -p $(DOBJS)

$(LIBFT):
	make -C libft

$(OBJS): $(DOBJS)/%.o: $(DSRCS)/%.c $(HEADER)
	$(GCC) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(DOBJS) $(OBJS) $(HEADER)
	$(GCC) -o $(NAME) $(OBJS) $(LFT)

clean:
	make clean -C libft
	rm -rf $(DOBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
