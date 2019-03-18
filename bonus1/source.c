/*
	bonus1.c
*/

/* compile: 	gcc -fno-stack-protector source.c 	*/

#include <stdlib.h>	/* atoi */
#include <unistd.h>	/* execl */
#include <string.h>	/* memcpy */

int main(int argc, char **argv)
{
	char	buf[40];
	int	k;

	k = atoi(argv[1]);
	if (k < 10) {
		memcpy(buf, argv[2], k * 4);
		if (k == 0x574f4c46) {
				execl("/bin/sh", "sh", NULL);
		}
	} else {
		return 1;
	}
	return 0;
}
