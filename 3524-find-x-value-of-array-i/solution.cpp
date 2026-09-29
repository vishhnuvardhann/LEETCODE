// 167 ms | 151.1 MB
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int i = 0; i < n; i++) {
            vector<long long> next(k, 0);
            int v = nums[i] % k;

            next[v]++;

            for (int j = 0; j < k; j++) {
                if (dp[j])
                    next[(j * v) % k] += dp[j];
            }

            dp = next;

            for (int j = 0; j < k; j++)
                ans[j] += dp[j];
        }

        return ans;
    }
};