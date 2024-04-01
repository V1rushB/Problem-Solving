class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> prefix(nums.size()+1,0);
        for(int o = 1;o <=nums.size();o++)
            prefix[o] = prefix[o-1] + nums[o-1];
        int l(1),r(1),mi = 1e6;
        while(r < prefix.size())
        {
            if(prefix[r] - prefix[l-1] >= target) {
                mi = min(mi,r-(l-1));
                l++;
                if(l>r)
                    r=l;
            }
            else {
                r++;
            }
        }
        return mi != 1e6? mi : 0;
    }
};
