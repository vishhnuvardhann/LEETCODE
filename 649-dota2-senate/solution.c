// 3 ms | 9.9 MB

#include <stdlib.h>
#include <string.h>

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);

    int *radiant = malloc(n * sizeof(int));
    int *dire = malloc(n * sizeof(int));

    int rFront = 0, rRear = 0;
    int dFront = 0, dRear = 0;

    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R')
            radiant[rRear++] = i;
        else
            dire[dRear++] = i;
    }

    while (rFront < rRear && dFront < dRear) {
        int r = radiant[rFront++];
        int d = dire[dFront++];

        if (r < d)
            radiant[rRear++] = r + n;
        else
            dire[dRear++] = d + n;
    }

    free(radiant);
    free(dire);

    return (rFront < rRear) ? "Radiant" : "Dire";
}
