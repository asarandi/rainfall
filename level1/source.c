#include <stdlib.h>
#include <stdio.h>

void		run(void)
{
	fwrite("Good... Wait what?\n", 1, 19, stdout);
	system("/bin/sh");
}

int			main(void)
{
	char	buffer[76];

	gets(buffer);
	return 0;
}
