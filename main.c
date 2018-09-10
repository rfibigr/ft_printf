#include "include/ft_printf.h"
#include "stdio.h"
#include "locale.h"

int main ()
{
//	setlocale(LC_ALL, "");
	char s;

	s = NULL;

	ft_printf(">------------<%6.2ls>------------<", s);
	printf("\n");
	printf(">------------<%6.2ls>------------<", s);
	printf("\n");

}
