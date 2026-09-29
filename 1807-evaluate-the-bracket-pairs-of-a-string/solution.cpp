// 69 ms | 122.8 MB
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto& x : knowledge)
            mp[x[0]] = x[1];

        string ans, key;
        bool inside = false;

        for (char c : s) {
            if (c == '(') {
                inside = true;
                key.clear();
            } else if (c == ')') {
                if (mp.count(key))
                    ans += mp[key];
                else
                    ans += '?';

                inside = false;
            } else {
                if (inside)
                    key += c;
                else
                    ans += c;
            }
        }

        return ans;
    }
};