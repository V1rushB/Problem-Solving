class Solution {
private:
    int dfs(int val, vector<int> &memo, int n) {
        if(val >= n) {
            return (val == n);
        }
        if(~memo[val]) {
            return memo[val];
        }
        memo[val] = dfs(val+1, memo, n) + dfs(val+2, memo, n);
        return memo[val];
    }
public:
    int climbStairs(int n) {
        vector<int> memo (n+1, -1);
        dfs(0, memo, n);
        return memo[0];
    }
};

