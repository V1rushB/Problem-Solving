class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int o = 0 ; o < nums.size();o++) {
            if(o > 0 && nums[o] == nums[o-1])
                continue;
            int l = o+1, r = nums.size()-1;
            while(r > l) {
                if((nums[o] + nums[l] + nums[r]) == 0) {
                    ans.push_back(vector<int>{nums[o],nums[l],nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                }

                else if(nums[o] + nums[l] + nums[r] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};

