#include <stdio.h>
#include <locale.h>
#include "include/ft_printf.h"

int main()
{
	int i;
	int j;

	i = 0;
	j = 0;

	setlocale(LC_ALL, "en_US.UTF-8");

	printf("MB_CUR_MAX = %zd\n", MB_CUR_MAX);
	i = ft_printf("%C\n", 0x90);
	j = printf("%C\n", 0x90);
	printf("i = %d, j = %d\n",i,j);
	return(1);
}
