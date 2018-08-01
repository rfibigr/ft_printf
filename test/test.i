# 1 "test.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "test.c"
#pragma GCC pch_preprocess "ft_printf.h.gch"
# 1 "libft.h" 1
# 3 "test.c" 2

int main(int ac, char **av)
{
 (void) ac;
 ft_printf(av[1], av[2], 
# 7 "test.c" 3 4
                        ((void *)0)
# 7 "test.c"
                            );
 printf("\n");
 printf(av[1], av[2], 
# 9 "test.c" 3 4
                     ((void *)0)
# 9 "test.c"
                         );
 return(0);
}
