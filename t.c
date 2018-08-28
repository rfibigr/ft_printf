#include "include/ft_printf.h"

int main ()
{
	char s[10] = "hello";
	int b = 10;
	ft_printf("Hello Wolrd %s %10.5d", s, b );
	return(0);
}
