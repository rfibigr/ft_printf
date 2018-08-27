#include <stdio.h>
#include <locale.h>
#include "include/ft_printf.h"

int main()
{
	int i;
	int j;
	wchar_t	s[4];

	setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0x53;
	s[2] = 0x81000;
	s[3] = '\0';

	printf("cc %%10.0ls et %%.ls et %%-2S%%-12S, s, s, s, s (0x53, 0x3abc 0x81000, 0)\n");
	i = printf("cc %10.0ls et %.ls et %-2S%-12S", s, s, s, s);
	printf("\n");
	j = ft_printf("cc %10.0ls et %.ls et %-2S%-12S", s, s, s, s);
	printf("\n");
	printf("i = %d| j = %d\n", i,j );
	printf("\n");

	printf("yo%%2C hello%%-12lc et %%C titi %%C tyty, 'u', 254, 256, 'a'\n");
	i = printf("yo%2C hello%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	printf("\n");
	j = ft_printf("yo%2C hello%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	printf("\n");
	printf("i = %d| j = %d\n", i,j );

	printf("%%-+-12.7Dt%%0 4i %%04.2%% et %%lc titi, 125, 124, 256\n");
	i = printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256);
	printf("\n");
	j = ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256);
	printf("\n");
	printf("i = %d| j = %d\n", i,j );
}
