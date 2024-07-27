#define ll long long int

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<ll,ll> mp;
        for(int o = 0; o < nums.size();o++) {
            mp[nums[o]]++;
        }
        for(auto &el : mp)
            if(el.second >= 2)
                return true;
        return false;
    }
};

