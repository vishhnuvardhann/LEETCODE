// 0 ms | 165.9 MB
class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        bool hasOdd = false;

        for (int x : nums) {
            if (x % 2)
                hasOdd = true;
        }

        if (mn % 2)
            return true;

        return !hasOdd;
    }
};