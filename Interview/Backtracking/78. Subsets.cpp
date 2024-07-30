class Solution {
public:

    vector<vector<int>> ans;
    vector<int> subset;

    void dfs(const vector<int> &nums, int o) {
        if(o >= nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[o]);
        dfs(nums,o+1);

        subset.pop_back();
        dfs(nums,o+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }
};

