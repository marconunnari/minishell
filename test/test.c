#include "../libft/includes/libft.h"

int		main(int argc, char **argv)
{
	char *str = "  a  ";
	char **arr = ft_strsplit(str, ' ');
	while(*arr)
		ft_printf("string: %s", *arr++);
}
