#include "../libft/includes/libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char *boh = NULL;
	char *bah;

	bah = (boh || "hello");
	printf("%s", boh);
}
