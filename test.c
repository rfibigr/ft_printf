#include <stdio.h>
#include <locale.h>
#include "include/ft_printf.h"

int main()
{
	wchar_t	s[4];

	setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0x53;
	s[2] = 0x81000;
	s[3] = '\0';

	//ft_printf("cc %10.0ls et %.ls et %-2S%-12S", s, s, s, s);
	//ft_printf("yo%2C hello%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	//ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256);
	printf("{%05.S}\n", L"42 c est cool");
	ft_printf("{%05.S}\n", L"42 c est cool");
	printf("{%03.2d}\n", 0);
	ft_printf("{%03.2d}\n", 0);
	return(0);
}
