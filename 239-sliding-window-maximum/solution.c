// 7 ms | 94.1 MB

#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;

    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int));

    int front = 0, rear = -1;

    for (int i = 0; i < numsSize; i++) {
        // Remove indices outside the current window
        while (front <= rear && deque[front] <= i - k) {
            front++;
        }

        // Remove smaller elements from the back
        while (front <= rear && nums[deque[rear]] <= nums[i]) {
            rear--;
        }

        deque[++rear] = i;

        // Record maximum once the first window is complete
        if (i >= k - 1) {
            result[i - k + 1] = nums[deque[front]];
        }
    }

    free(deque);
    return result;
}
