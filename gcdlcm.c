/* File: gcdlcm.c */

#include <stdio.h>
#include <stdlib.h>        /* Header file for srand and rand functions */
#include <time.h>                     /* Header file for time function */
#define COMPUTATIONS 20     /* Pairs of numbers to compute GCD and LCM */
#define MAXNUMB 30000                                /* Maximum number */

int main() {
    int i, m, n, large, small, gcd, lcm, rem, curtime;
    curtime = time(NULL);  /* Current time (in seconds since 1/1/1970) */
    printf("Current time is %d\n\n", curtime);
    srand((unsigned int) curtime); /* Seed for random number generator */
    for (i = 0 ; i < COMPUTATIONS ; i++) {
        m = rand() % MAXNUMB + 1;  /* Select 1st number in [1,MAXNUMB] */
        n = rand() % MAXNUMB + 1;  /* Select 2nd number in [1,MAXNUMB] */
        if (m > n) {                        /* Which number is larger? */
            large = m;                                  /* Larger is m */
            small = n;
        }
        else {
            large = n;                                  /* Larger is n */
            small = m;
        }
        while (small) {                        /* While small is not 0 */
            rem = large % small;      /* Find remainder of large/small */
            large = small;              /* New large is previous small */
            small = rem;               /* New small is remainder found */
        }
        gcd = large;  /* GCD of m and n equals to final value of large */
        lcm = (m * n) / gcd;            /* LCM(m,n) * GCD(m,n) = m * n */
        printf("GCD(%5d, %5d) = %3d      LCM(%5d, %5d) = %10d\n",
               m, n, gcd, m, n, lcm);
    }
    return 0;
}
