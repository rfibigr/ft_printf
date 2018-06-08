all : printf.o
	make -C ../lib/libft
	gcc -o printf printf.o ../lib/libft/libft.a

printf.o : printf.c
	gcc -c printf.c

clean :
	make clean -C ../lib/libft
	rm -rf printf.o
	rm -rf printf
