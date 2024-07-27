#define ll long long int

class Solution {
public:
    bool isAnagram(string s, string t) {
        ll a(s.size());
        vector<ll> d(26,0);
        for(auto &el : s)
            d[el-'a']++;
        
        for(auto &el : t)
            d[el-'a']--;

        for(auto &el : d)
            if(el)
                return false;
        return true;
    }
};

