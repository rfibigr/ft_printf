#include "ft_printf.h"
#include "libft.h"

int main(int ac, char **av)
{
	(void) ac;
	ft_printf(av[1], ft_atoi(av[2]), ft_atoi(av[3]));
	printf("\n");
	printf(av[1], ft_atoi(av[2]), ft_atoi(av[3]));
	return(0);
}
