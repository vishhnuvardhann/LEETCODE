// 7 ms | 8.7 MB
class Solution {
public:
    int countCommas(int n) {
        if (n < 1000)
            return 0;

        int ans = 0;

        for (int i = 1000; i <= n; i++) {
            int x = i;

            while (x >= 1000) {
                ans++;
                x /= 1000;
            }
        }

        return ans;
    }
};