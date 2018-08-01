#include "ft_printf.h"
#include "libft.h"

int main(int ac, char **av)
{
	(void) ac;
	(void**) av;
	ft_printf("%%d 2147483648 = %d | %%d -2147483648 = %d |",2147483648, -2147483648);
	printf("\n");
	printf("%%d 2147483648 = %d | %%d -2147483648 = %d |",2147483648, -2147483648);
	return(0);
}
