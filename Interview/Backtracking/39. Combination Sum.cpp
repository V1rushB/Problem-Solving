class Solution {

private:
    vector<vector<int>> ans;
    vector<int> subset;

    void dfs(const vector<int> &d, int target, int currentValue, int o) {
        if(target == currentValue) {
            ans.push_back(subset);
            return;
        }

        if(o >= d.size() || currentValue > target) {
            return;
        }

        subset.push_back(d[o]);
        dfs(d, target, currentValue+d[o], o);
        subset.pop_back();
        dfs(d, target, currentValue, o+1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums,target,0,0);
        return ans;
    }
};

