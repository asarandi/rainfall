/*
	source3.c
*/

#include <stdio.h>
#include <stdlib.h>

static int	g_var = 0;

void 		v(void)
{
	char	buffer[512];

	fgets(buffer, 512, stdin);
	printf(buffer);
	if (g_var == 64)
	{
		fwrite("Wait what?!\n", 1, 12, stdout);
		system("/bin/sh");
	}
}

int			main(void)
{
	v();
	return 0;
}
