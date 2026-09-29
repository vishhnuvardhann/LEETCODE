// 68 ms | 96.4 MB
class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(n, vector<long long>(k + 1));
        vector<vector<long long>> open(n, vector<long long>(k + 1));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                open[i][j] = open[i - 1][j] + dp[i - 1][j - 1];
                open[i][j] %= MOD;

                dp[i][j] += open[i][j];
                dp[i][j] %= MOD;
            }
        }

        return dp[n - 1][k];
    }
};