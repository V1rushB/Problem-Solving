class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<pair<int,int>> pfx(nums.size());
        int last = 1;
        for(int o = 0; o <pfx.size();o++) {
            pfx[o].first = last;
            last*=nums[o];
        }
        last = 1;
        for(int o = pfx.size()-1; o >= 0;o--) {
            pfx[o].second = last;
            last*=nums[o];
        }
        vector<int> ans(nums.size());
        for(int o = 0; o < ans.size();o++)
            ans[o] = pfx[o].first * pfx[o].second;
        return ans;
    }
};
