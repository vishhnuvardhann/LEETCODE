// 0 ms | 12 MB

double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size,
                                      nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int low = 0, high = m;

    while (low <= high) {
        int i = low + (high - low) / 2;
        int j = (m + n + 1) / 2 - i;

        int left1  = (i == 0) ? -2147483647 - 1 : nums1[i - 1];
        int right1 = (i == m) ?  2147483647     : nums1[i];
        int left2  = (j == 0) ? -2147483647 - 1 : nums2[j - 1];
        int right2 = (j == n) ?  2147483647     : nums2[j];

        if (left1 <= right2 && left2 <= right1) {
            if ((m + n) % 2 == 0) {
                int maxLeft = (left1 > left2) ? left1 : left2;
                int minRight = (right1 < right2) ? right1 : right2;
                return ((double)maxLeft + minRight) / 2.0;
            }

            return (double)((left1 > left2) ? left1 : left2);
        } else if (left1 > right2) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }

    return 0.0;
}
