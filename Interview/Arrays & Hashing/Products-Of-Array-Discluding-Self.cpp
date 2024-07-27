class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int a(nums.size());
        vector<int> ans(a,1);
        int mul(1);
        for(int o = 0; o < a;o++) {
            ans[o] = mul;
            mul*=nums[o];
        }
        mul = 1;
        for(int o = a-1; o >= 0;o--) {
            ans[o]*=mul;
            mul*=nums[o];
        }
        return ans;
    }
};

