#define ll long long int

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        ll a = nums.size();
        set<ll> st;
        ll prev(st.size());
        for(int o = 0; o < a;o++) {
            st.insert(nums[o]);
            if(prev == st.size())
                return true;
            prev = st.size();
        }
        return false; 
    }
};

