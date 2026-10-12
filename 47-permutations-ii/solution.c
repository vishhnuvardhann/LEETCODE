// 3 ms | 14.6 MB
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

void backtrack(int *nums, int numsSize, int *used,
               int *path, int depth,
               int **result, int *returnSize,
               int **returnColumnSizes) {

    if (depth == numsSize) {
        result[*returnSize] =
            (int *)malloc(numsSize * sizeof(int));

        for (int i = 0; i < numsSize; i++)
            result[*returnSize][i] = path[i];

        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i])
            continue;

        // Skip duplicate choices at the same level
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        used[i] = 1;
        path[depth] = nums[i];

        backtrack(nums, numsSize, used, path, depth + 1,
                  result, returnSize, returnColumnSizes);

        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize,
                    int* returnSize, int** returnColumnSizes) {

    int maxResults = 1;

    for (int i = 2; i <= numsSize; i++)
        maxResults *= i;

    int **result = malloc(maxResults * sizeof(int *));
    *returnColumnSizes = malloc(maxResults * sizeof(int));
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    int *used = calloc(numsSize, sizeof(int));
    int *path = malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, used, path, 0,
              result, returnSize, returnColumnSizes);

    free(used);
    free(path);

    return result;
}