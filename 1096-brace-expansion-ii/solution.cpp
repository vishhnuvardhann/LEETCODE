// 11 ms | 17.9 MB
class Solution {
public:
    int pos = 0;

    set<string> parse(string& s) {
        set<string> res = parseTerm(s);

        while (pos < s.size() && s[pos] == ',') {
            pos++;
            set<string> next = parseTerm(s);
            res.insert(next.begin(), next.end());
        }

        return res;
    }

    set<string> parseTerm(string& s) {
        set<string> res = {""};

        while (pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> cur = parseUnit(s);
            set<string> next;

            for (auto& a : res)
                for (auto& b : cur)
                    next.insert(a + b);

            res = next;
        }

        return res;
    }

    set<string> parseUnit(string& s) {
        set<string> res;

        if (s[pos] == '{') {
            pos++;
            res = parse(s);
            pos++;
        } else {
            res.insert(string(1, s[pos]));
            pos++;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        set<string> res = parse(expression);
        return vector<string>(res.begin(), res.end());
    }
};