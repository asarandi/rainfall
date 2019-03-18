/*
    bonus2.c
*/

/* compile:
    gcc bonus2.c -fno-stack-protector -z execstack -o ft_bonus2
*/

#include <stdlib.h>     /* getenv */
#include <stdio.h>      /* puts */
#include <string.h>     /* strcat */

static int language;

void greetuser(char *user)
{
    char buf[64] = {0};

    if (language == 1) {
        strcat(buf, "Hyvää päivää ");   // 18 bytes (LANG == "fi")
    } else if (language == 2) {
        strcat(buf, "Goedemiddag! ");   // 13 bytes (LANG == "nl")
    } else {
        strcat(buf, "Hello ");          // 6 bytes
    }
    puts(strcat(buf, user));
}

int main(int argc, char **argv)
{
    char    buf[72] = {0};
    char    *env = NULL;

    if (argc != 3)
        return 1;

    strncpy(buf, argv[1], 40);
    strncpy(&buf[40], argv[2], 32);
    env = getenv("LANG");
    if (memcmp(env, "fi", 2) == 0) {
        language = 1;
    } else if (memcmp(env, "nl", 2) == 0) {
        language = 2;
    }

    greetuser(buf);
    return 0;
}
