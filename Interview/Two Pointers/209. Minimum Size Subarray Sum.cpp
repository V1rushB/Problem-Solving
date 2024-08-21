class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l(0), r(0), mi(1e5+5), s(0);
        
        while(r < nums.size()) {
            s+=nums[r++];
            if(s >= target && l < r) {
                while(s >= target && l < r) {
                    s-=nums[l++];
                }
                mi = min(mi, (r - l) + 1);
            }
        }
        return mi == 1e5+5 ? 0 : mi;
    }
};

