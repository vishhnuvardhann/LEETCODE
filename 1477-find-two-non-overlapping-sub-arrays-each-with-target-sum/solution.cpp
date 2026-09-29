// 179 ms | 142.7 MB
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);
        unordered_map<int, int> mp;

        int sum = 0;
        int ans = INF;
        int bestLen = INF;

        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (mp.count(sum - target)) {
                int j = mp[sum - target];
                int len = i - j;

                if (j >= 0 && best[j] != INF)
                    ans = min(ans, len + best[j]);

                bestLen = min(bestLen, len);
            }

            best[i] = bestLen;
            mp[sum] = i;
        }

        return ans == INF ? -1 : ans;
    }
};