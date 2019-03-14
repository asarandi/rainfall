#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>

# define SHELL "/bin/sh"

int			main(int argc, char **argv)
{
	char	*exec_args[2];
	gid_t	egid;
	uid_t	euid;

	if (atoi(argv[1]) == 423)
	{
		exec_args[0] = strdup(SHELL);
		exec_args[1] = NULL;
		egid = getegid();             // unnecessary
		euid = geteuid();             // unnecessary
		setresgid(egid, egid, egid);  // unnecessary
		setresuid(euid, euid, euid);  // unnecessary
		execv(SHELL, exec_args);
	}
	else
	{
		fwrite("No !\n", 1, 5, stderr);
	}
	return 0;
}
