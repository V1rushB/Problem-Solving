typedef pair<int,int> pi;
class Solution {
    int rows, cols;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};
    const int MOD = 1e9 + 7;

    int dfs(pi val, vector<vector<int>> &d, map<pi, int> &memo) {
        memo[val] = 1;

        int depth(1);
        for(int o = 0; o < 4;o++) {
            int x = val.first + dx[o];
            int y = val.second + dy[o];
            pi next = make_pair(x,y);
            if(x < 0 || y < 0 || x >= rows || y >= cols || d[x][y] <= d[val.first][val.second])
                continue;
            if(!memo[next]) {
                memo[val] = (memo[val] + dfs(next, d, memo)) % MOD;
            } else {
                memo[val] = (memo[val] + memo[next]) % MOD; 
            }
        }
        return memo[val];
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        map<pi, int> memo;
        int s(0);
        for(int o = 0; o < rows;o++) {
            for(int i = 0; i < cols;i++) {
                s= (s+dfs(make_pair(o,i), grid, memo)) % MOD;
            }
        }
        return s;
    }
};
