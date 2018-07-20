#include <stdio.h>

int main ()
{
	printf("+d	start|%+d|end\n", 1235);
	printf(" d	start|% d|end\n", 1235);
	printf("+10d	start|%+10d|end\n", 1235);
	printf(" 10d	start|% 10d|end\n", 1235);
	printf("+.10d	start|%+.10d|end\n", 1235);
	printf(" .10d	start|% .10d|end\n", 1235);
	printf("+010d	start|%+010d|end\n", 1235);
	printf(" 010d	start|% 010d|end\n", 1235);
	printf("+15.5d	start|%+15.5d|end\n", 1235);
	printf(" 15.5d	start|% 15.5d|end\n", 1235);
	printf("+5.15d	start|%+5.15d|end\n", 1235);
	printf(" 5.15d	start|% 5.15d|end\n", 1235);
	printf("-+15.5d	start|%-+15.5d|end\n", 1235);
	printf("- 15.5d	start|%- 15.5d|end\n", 1235);
	printf("-+5.15d	start|%-+5.15d|end\n", 1235);
	printf("- 5.15d	start|%- 5.15d|end\n", 1235);
	return (0);
}



