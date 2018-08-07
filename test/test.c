#include "ft_printf.h"
#include "libft.h"

int main()
{
	ft_printf("ft_printf:%p",0);
	printf("\n");
	printf("   printf:%p",0);
	printf("\n");
	printf("\n");
	ft_printf("ft_printf:%.p",0);
	printf("\n");
	printf("   printf:%.p",0);
	printf("\n");
	printf("\n");

	ft_printf("ft_printf:%");
	printf("\n");
	printf("printf:%");
	printf("\n");
	printf("\n");


	return(0);
}
