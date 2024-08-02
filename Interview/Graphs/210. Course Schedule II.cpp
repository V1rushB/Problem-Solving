class Solution {
    int rows, cols;
    vector<int> ans;

    bool dfs(int val, map<int, vector<int>> &mp, vector<bool> &visited) {
        if(visited[val])
            return false;

        if (mp[val].empty()) {
            if (find(ans.begin(), ans.end(), val) == ans.end()) {
                ans.push_back(val);
            }
            return true;
        }

        visited[val] = true;

        for(int el : mp[val]) {
            if(!dfs(el, mp,visited)) {
                return false;
            }
        }
        if (find(ans.begin(), ans.end(), val) == ans.end()) {
            ans.push_back(val);
        }
        visited[val] = false;
        mp[val].clear();
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int> res(numCourses);
        if(!prerequisites.size()) {
                iota(res.begin(), res.end(), 0);
                return res;
        }
            map<int, vector<int>> mp;
            vector<bool> visited(numCourses,false);
            for(int o  =0; o < prerequisites.size();o++) {
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
