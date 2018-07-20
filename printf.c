#include <stdio.h>

int main ()
{
	printf("start|%o|end\n", 1235);
	printf("start|%0.10o|end\n", 1235);
	printf("start|%015.o|end\n", 1235);
	printf("start|%010.15o|end\n", 1235);
	printf("start|%10o|end\n", 1235);
	printf("start|%.10o|end\n", 1235);
	printf("start|%15.10o|end\n", 1235);
	printf("start|%10.15o|end\n", 1235);
	printf("start|%1d|end\n", 1235);
	printf("start|%.1d|end\n", 1235);
	return (0);
}



