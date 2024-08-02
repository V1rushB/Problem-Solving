class Solution {
    int rows, cols;

    bool dfs(int val, map<int, vector<int>> &mp, vector<bool> &visited) {
        if(visited[val])
            return false;
        if(mp[val].empty())
            return true;

        visited[val] = true;
        for(int el : mp[val]) {
            if(!dfs(el, mp, visited)) {
                return false;
            }
        }

        mp[val].clear();
        visited[val] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(!prerequisites.size())
            return true;
        rows = prerequisites.size();
        cols = prerequisites[0].size();

        map<int, vector<int>> mp;
        vector<bool> visited(numCourses,false);
        for(int o  =0; o < rows;o++) {
            int u = prerequisites[o][0];
            int v = prerequisites[o][1];
            mp[u].push_back(v);
        }

        for(int o = 0; o < numCourses;o++) {
            if(!dfs(o, mp, visited)) {
                return false;
            }
        }
        return true;
    }
};
