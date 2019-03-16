/*
	source2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char 		*p(void)
{
	char	buffer[64];
	void	*ret_addr;

	fflush(stdout);
	gets(buffer);
	ret_addr = __builtin_return_address(0);
	if (((unsigned long)ret_addr & 0xb0000000) == 0xb0000000)
	{
		printf("(%p)\n", ret_addr);
		exit(1);
	}
	puts(buffer);
	return strdup(buffer);
}

int			main(void)
{
	return (int)p();
}
