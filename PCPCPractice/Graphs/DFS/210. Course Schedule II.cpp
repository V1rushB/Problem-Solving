class Solution {
private:
    int rows, cols;
    vector<int> ans;

    bool dfs(int val, map<int, vector<int>> &mp, vector<bool> &visited) {
        if(visited[val])
            return false;
        if(!mp[val].size()) {
            if(find(ans.begin(), ans.end(), val) == ans.end()) {
                ans.push_back(val);
            }
            return true;
        }
        visited[val] = true;

        for(auto el : mp[val]) {
            if(!dfs(el, mp, visited))
                return false;
        }

        if(find(ans.begin(), ans.end(), val) == ans.end()) {
            ans.push_back(val);
        }
        visited[val] = false;
        mp[val].clear();
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
                return {};
            }
        }
        return ans;
    }
};

