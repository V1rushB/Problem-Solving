class Solution {
private:
    int rows, cols;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};

    int dfs(pair<int,int> pt, map<pair<int,int>, int> &memo, vector<vector<int>> &matrix) {
        memo[pt] = 1;
        int x = pt.first;
        int y = pt.second;
        int globalDepth(1);
        for(int o = 0; o < 4;o++) {
            int row = x + dx[o];
            int col = y + dy[o];

            pair<int,int> current = make_pair(row,col);
            if(row < 0 || col < 0 || row >= rows || col >= cols || matrix[x][y] >= matrix[row][col])
                continue;
            if(!memo[current]) {
                globalDepth = max(globalDepth, dfs(current,memo, matrix) + 1);
            } else {
                globalDepth = max({globalDepth, memo[{x,y}], memo[current] + 1});
            }
        }
        memo[make_pair(x,y)] = globalDepth;
        return globalDepth;
    }
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size(); cols = matrix[0].size();
        map<pair<int,int>, int> memo;

        int mx = -1;
        for(int o = 0; o < rows;o++) {
            for(int i = 0; i < cols;i++) {
                if(!memo[make_pair(o,i)])
                   mx = max(mx, dfs(make_pair(o,i), memo, matrix));
            }
        }

        cout << "THING!" << endl;
        for(auto el : memo) {
            // cout << //(1,1)
            cout << '(' << el.first.first << ", " << el.first.second << ") ->" << el.second << endl;; 
        }
        return mx;
    }
};
