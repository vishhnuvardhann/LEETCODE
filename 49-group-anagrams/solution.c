// 968 ms | 249 MB
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compareChars(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

char* sortedString(const char *s) {
    char *key = malloc(strlen(s) + 1);
    strcpy(key, s);
    qsort(key, strlen(key), sizeof(char), compareChars);
    return key;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize,
                      int** returnColumnSizes) {
    char ***result = malloc(strsSize * sizeof(char **));
    int *colSizes = malloc(strsSize * sizeof(int));
    char **keys = malloc(strsSize * sizeof(char *));

    *returnSize = 0;

    for (int i = 0; i < strsSize; i++) {
        char *key = sortedString(strs[i]);
        int group = -1;

        for (int g = 0; g < *returnSize; g++) {
            if (strcmp(keys[g], key) == 0) {
                group = g;
                break;
            }
        }

        if (group == -1) {
            group = (*returnSize)++;
            result[group] = malloc(strsSize * sizeof(char *));
            colSizes[group] = 0;
            keys[group] = key;
        } else {
            free(key);
        }

        result[group][colSizes[group]++] = strs[i];
    }

    *returnColumnSizes = colSizes;
    return result;
}