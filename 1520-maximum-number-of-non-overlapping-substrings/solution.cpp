// 8 ms | 23.4 MB
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (first[c] == -1)
                first[c] = i;

            last[c] = i;
        }

        vector<pair<int, int>> ranges;

        for (int c = 0; c < 26; c++) {
            if (first[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];
            bool ok = true;

            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                if (first[x] < l) {
                    ok = false;
                    break;
                }

                r = max(r, last[x]);
            }

            if (ok)
                ranges.push_back({l, r});
        }

        sort(ranges.begin(), ranges.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });

        vector<string> ans;
        int end = -1;

        for (auto& [l, r] : ranges) {
            if (l > end) {
                ans.push_back(s.substr(l, r - l + 1));
                end = r;
            }
        }

        return ans;
    }
};