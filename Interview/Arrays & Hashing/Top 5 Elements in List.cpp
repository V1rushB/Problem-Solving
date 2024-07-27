class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        multimap<int,int> mp2;
        for(auto &el : nums)
            mp[el]++;
        
        for(auto &el : mp)
            mp2.insert(pair<int,int>(el.second,el.first));
        
        auto it = mp2.end();
        vector<int> ans;
        while(k--) {
            ans.push_back((*(--it)).second);
        }
        return ans;
        
    }
};

