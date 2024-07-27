class Solution {
public:

    bool isAngram(string str, string b) {
        vector<int> d(26,0);
        for(auto &el : str)
            d[el-'a']++;
        for(auto &el : b)
            d[el-'a']--;
        for(auto el : d)
            if(el)
                return false;
        return true;
        
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int a = strs.size();
        vector<vector<string>> ans;
        vector<pair<string,bool>> d(a);
        transform(strs.begin(), strs.end(), d.begin(), [](string str) {
            return make_pair(str, false);
        });
        for(int o = 0; o < a;o++) {
            if(d[o].second)
                continue;
            vector<string> temp = {d[o].first};
            for(int i = 0; i < a;i++) {
                if(o==i)
                    continue;
                if(isAngram(d[o].first,d[i].first)) {
                    temp.push_back(d[i].first);
                    d[i].second = true;
                }
            }
            ans.push_back(temp);
        } 
        return ans;
    }
};

