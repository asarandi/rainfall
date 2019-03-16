/*
	source7.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char			g_buffer[69];

void 			m(void)
{
	printf("%s - %d\n", g_buffer, time(0));
}

int				main(int argc, char **argv)
{
	int			*a;
	int			*b;

	a = malloc(8);
	a[0] = 0x1;
	a[1] = malloc(8);

	b = malloc(8);
	b[0] = 0x2;
	b[1] = malloc(8);

	strcpy((char *)a[1], argv[1]);
	strcpy((char *)b[1], argv[2]);

	fgets(g_buffer, 68, fopen("/home/user/level8/.pass", "r"));
	puts("~~");
	return 0;
}
