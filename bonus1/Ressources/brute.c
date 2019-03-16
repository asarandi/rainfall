
/* 
** find an int that is negative (less than 0)
** but when multiplied by 4 becomes positive
** greater or equal to 44 and but not much greater
*/

#include <stdio.h>
#include <limits.h>

int main()
{
    for (int i=-1; i > INT_MIN ; i--) {
        int x = i * 4;
        if (x >= 44 && x < 50) {
            printf("i = %d, j = 4, i*j = %d\n", i, x);
        }
    }
    return 0;
}


/* e1z4r12p11% gcc brute.c
 * e1z4r12p11% ./a.out    
 * i = -1073741812, j = 4, i*j = 48
 * i = -1073741813, j = 4, i*j = 44
 * i = -2147483636, j = 4, i*j = 48
 * i = -2147483637, j = 4, i*j = 44
 */
