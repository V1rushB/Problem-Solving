class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s(0);
        for(int o = 1; o <= nums.size();o++) {
            s ^=o;
        }
        for(auto &el : nums) {
            s^=el;
        }
        return s;
    }
};
