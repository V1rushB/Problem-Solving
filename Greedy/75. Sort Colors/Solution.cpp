class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mp;
        for(int &el : nums)
            mp[el]++;
        int o(0);
        for(auto &el : mp) {
            for(int i = 0; i < el.second;i++) {
                nums[o++] = el.first;
            }
        }
    }
};
