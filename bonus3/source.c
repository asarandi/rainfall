#include <stdio.h>      /* fopen, fread, fclose */
#include <unistd.h>     /* execl */
#include <stdlib.h>     /* atoi */
#include <string.h>     /* strcmp */

// #define pass_file "/home/user/end/.pass"
#define pass_file "flag"

int main(int argc, char **argv)
{
    int ret;
    int k;
    char buf[0x84];
    FILE *fp = fopen(pass_file, "r");

    for (int i=0; i<0x84; i++) {    /* clear buffer */
        buf[i] = 0;
    }

    if ((!fp) || (argc != 2)) {
        ret = -1;
    } else {
        fread(buf, 1, 0x42, fp);
        buf[16] = 0;                /* 0x8048574 */
        buf[atoi(argv[1])] = 0;
        fread(&buf[0x42], 1, 0x41, fp);
        fclose(fp);

        if (strcmp(buf, argv[1]) == 0) {
            execl("/bin/sh", "sh", 0);
        } else {
            puts(&buf[0x42]);
        }

        ret = 0;
    }
    return ret;
}
