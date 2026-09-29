// 1 ms | 128.6 MB
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;
        int i = 1;

        ListNode* prev = head;
        ListNode* cur = head->next;

        while (cur && cur->next) {
            if ((cur->val > prev->val && cur->val > cur->next->val) ||
                (cur->val < prev->val && cur->val < cur->next->val)) {
                pos.push_back(i);
            }

            prev = cur;
            cur = cur->next;
            i++;
        }

        if (pos.size() < 2)
            return {-1, -1};

        int mn = INT_MAX;

        for (int j = 1; j < pos.size(); j++)
            mn = min(mn, pos[j] - pos[j - 1]);

        int mx = pos.back() - pos.front();

        return {mn, mx};
    }
};