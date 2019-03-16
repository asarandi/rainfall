/*
	source8.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char			buffer[129];

char			*auth = NULL;
char			*service = NULL;

int				main(int argc, char **argv)
{
	while (1)
	{
		printf("%p, %p \n", auth, service);	

		if (fgets(buffer, 128, stdin) == NULL)
			break;

		if (strncmp(buffer, "auth ", 5) == 0)
		{
			auth = malloc(4);
			auth[0] = '\0';
			if (strlen(buffer + 5) + 1 <= 30)
				strcpy(auth, buffer + 5);
		}

		if (strncmp(buffer, "reset", 5) == 0)
			free(auth);

		if (strncmp(buffer, "service", 6) == 0)
			service = strdup(buffer + 7);

		if (strncmp(buffer, "login", 5) == 0)
		{
			if (auth[32] == '\0')
				fwrite("Password:\n", 1, 10, stdout);
			else
				system("/bin/sh");
		}
	}
	return 0;
}
