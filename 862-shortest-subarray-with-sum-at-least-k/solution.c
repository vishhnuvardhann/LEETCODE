// 8 ms | 18.8 MB

#include <stdlib.h>
#include <limits.h>

int shortestSubarray(int* nums, int numsSize, int k) {
    long long *prefix = malloc((numsSize + 1) * sizeof(long long));
    int *deque = malloc((numsSize + 1) * sizeof(int));

    prefix[0] = 0;

    for (int i = 0; i < numsSize; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    int front = 0, rear = 0;
    int result = numsSize + 1;

    for (int i = 0; i <= numsSize; i++) {
        while (front < rear &&
               prefix[i] - prefix[deque[front]] >= k) {
            int length = i - deque[front];
            if (length < result)
                result = length;
            front++;
        }

        while (front < rear &&
               prefix[i] <= prefix[deque[rear - 1]]) {
            rear--;
        }

        deque[rear++] = i;
    }

    free(prefix);
    free(deque);

    return result == numsSize + 1 ? -1 : result;
}
