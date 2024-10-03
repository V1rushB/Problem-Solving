class Solution {
private:
    int rows, cols;

    bool dfs(int val, map<int, vector<int>> &mp, vector<bool> &visited) {
        if(visited[val])
            return false;
        if(!mp[val].size())
            return true;
        visited[val] = true;

        for(auto el : mp[val]) {
            if(!dfs(el, mp, visited)) {
                return false;
            }
        }
        visited[val] = false;
        mp[val].clear();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        rows = prerequisites.size(), cols = 2;
        map<int, vector<int>> mp;
        vector<bool> visited(numCourses, false);
        for(int o = 0; o < rows;o++) {
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

