all : printf.o
	make -C ../lib/libft
	clang -o printf printf.o ../lib/libft/libft.a

printf.o : printf.c
	clang -c printf.c

clean :
	make clean -C ../lib/libft
	rm -rf printf.o
	rm -rf printf
