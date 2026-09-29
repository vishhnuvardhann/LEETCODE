// 30 ms | 9.4 MB
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];

            for (int j = i - k; j >= 0; j--) {
                if (i - j < k)
                    continue;

                bool ok = true;

                for (int l = j, r = i - 1; l < r; l++, r--) {
                    if (s[l] != s[r]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    break;
                }
            }
        }

        return dp[n];
    }
};