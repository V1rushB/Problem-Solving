class Solution {
private:
    int rows, cols;
    vector<string> ans;

    void dfs(string val, map<string, vector<string>> &mp) {
        vector<string> children = mp[val];
        while(!children.empty()) {
            string str = children[0];
            mp[val].erase(mp[val].begin());
            dfs(str, mp);
            children = mp[val];
        }
        ans.push_back(val);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        rows = tickets.size(); cols = tickets[0].size();

        map<string, vector<string>> mp;
        for (int o = 0; o < rows; o++) {
            mp[tickets[o][0]].push_back(tickets[o][1]);
        }

        for(auto &el : mp) {
            sort(el.second.begin(), el.second.end());
        }
        dfs("JFK", mp);
        return {ans.rbegin(),ans.rend()};
    }
};

