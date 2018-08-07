#include "ft_printf.h"
#include "libft.h"

int main(int ac, char **av)
{
	(void) ac;
	
	ft_printf("ft_printf: %5%");
	printf("\n");
	printf("printf: %5%");
	printf("\n");

	ft_printf("ft_printf: %-5%");
	printf("\n");
	printf("printf: %-4%");
	printf("\n");

	ft_printf("%zd",-1);
	printf("\n");
	printf("%zd",-1);
	printf("\n");

	ft_printf("%U",4294967295);
	printf("\n");
	printf("%U",4294967295);
	printf("\n");

//	ft_printf("%hU",4294967295);
//	printf("\n");
//	printf("%hU",4294967295);
//	ft_printf("ft_printf : |%.p| |%.0p|", 0, 0);
//	printf("\n");
//	printf("   printf : |%.p| |%.0p|", 0, 0);
	return(0);
}
