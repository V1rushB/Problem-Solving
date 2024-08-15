class Solution {
    int dfs(vector<int> &memo, vector<int> &cost, int o) {
        if(o >= cost.size())
            return 0;
        int val = cost[o];
        if(~memo[o]) {
            return memo[o];
        }
            
        memo[o] = cost[o] + min(dfs(memo, cost, o+1), dfs(memo, cost, o+2));
        return memo[o];

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n+1, -1);
        return min(dfs(memo, cost, 0), dfs(memo, cost, 1));
    }
};

