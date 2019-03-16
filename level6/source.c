/*
	source6.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void			n(void)
{
	system("/bin/cat /home/user/level7/.pass");
}

void 			m(void)
{
	puts("Nope");
}

typedef void (*func_ptr_t)(void);

int				main(int argc, char **argv)
{
	char		*a;
	char		*b;
	func_ptr_t	func;

	a = malloc(64);
	b = malloc(4);

	*((unsigned long *)b) = (unsigned long)m;
	a = strcpy(a, argv[1]);
	func = *((func_ptr_t *)b);
	func();
	return 0;
}
