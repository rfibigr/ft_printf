#include <stdio.h>
#include <locale.h>
#include "include/ft_printf.h"

int main()
{
	int i;
	int j;

	setlocale(LC_ALL, "en_US.UTF-8");
	i = printf("%15.4S", L"我是一只猫。");
	printf("\n");
	j = ft_printf("%15.4S", L"我是一只猫。");
	printf("\n");
	//i = (printf("%15.6S\n", L"我是一只猫。"));
//	j = (ft_printf("%15.6S\n", L"我是一只猫。"));
	printf("i = %d| j = %d\n", i,j );

	i = printf("{%05.%}\n", 0);
	j = ft_printf("{%05.%}\n", 0);
	printf("i = %d| j = %d\n", i,j );
}
