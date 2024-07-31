class Solution {
private:
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,1,0,-1};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int,int>> dq;
        int s(0);
        int rows = grid.size();
        int cols = grid[0].size();
        for(int o = 0; o < rows;o++) {
            for(int i = 0; i < cols;i++) {
                if(grid[o][i] == 2)
                    dq.push_back(make_pair(o,i));
                else if(grid[o][i] == 1)
                    s++;
            }
        }

        vector<vector<int>> ans(rows, vector<int>(cols,-1));
        int level(0);
        while(!dq.empty() && s) {

            int current_level = dq.size();
            for(int o = 0; o < current_level;o++) {
                int row = dq.front().first;
                int col = dq.front().second;
                dq.pop_front();

                for(int i = 0; i < 4;i++) {
                    int x = row + dx[i];
                    int y = col + dy[i];
                    if(x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        dq.push_back(make_pair(x,y));
                        s--;
                    }
                }
            }
            level++;
        }
        return !s ? level : -1;
    }
};

