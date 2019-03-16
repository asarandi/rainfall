/*
	source4.c
*/

#include <stdio.h>
#include <stdlib.h>

static int	g_var = 0;

void		p(char *arg1)
{
	printf(arg1);
}

void 		n(void)
{
	char	buffer[512];

	fgets(buffer, 512, stdin);
	p(buffer);
	if (g_var == 0x1025544)
	{
		system("/bin/cat /home/user/level5/.pass");
	}
}

int			main(void)
{
	n();
	return 0;
}
