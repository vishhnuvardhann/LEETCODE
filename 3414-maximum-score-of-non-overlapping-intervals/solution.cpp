// 889 ms | 321.9 MB
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            return x[1] < y[1];
        });

        vector<int> ends(n);
        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] = lower_bound(ends.begin(), ends.begin() + i, a[i][0]) - ends.begin();
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> take(n + 1, vector<vector<int>>(5));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 4; j++) {
                dp[i][j] = dp[i - 1][j];
                take[i][j] = take[i - 1][j];

                if (j > 0) {
                    int p = prev[i - 1];
                    long long value = dp[p][j - 1] + a[i - 1][2];
                    vector<int> cur = take[p][j - 1];
                    cur.push_back(a[i - 1][3]);
                    sort(cur.begin(), cur.end());

                    if (value > dp[i][j] ||
                        (value == dp[i][j] && cur < take[i][j])) {
                        dp[i][j] = value;
                        take[i][j] = cur;
                    }
                }
            }
        }

        return take[n][4];
    }
};