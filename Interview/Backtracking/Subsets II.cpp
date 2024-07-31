class Solution {
private:
    set<vector<int>> ans;
    vector<int> subset;
    void dfs(const vector<int> &d, int o) {
        if(o >= d.size()) {
            ans.insert(subset);
            return;
        }
        subset.push_back(d[o]);
        dfs(d, o+1);
        subset.pop_back();

        while(o + 1 < d.size() && d[o] == d[o+1])
            ++o;
        dfs(d, o+1);
    }


public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};

