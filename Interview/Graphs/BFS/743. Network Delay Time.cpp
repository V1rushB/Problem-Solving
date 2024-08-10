typedef pair<int,int> pi;

class Solution {
private:
    int rows, cols;

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        rows = times.size(); cols = times[0].size();
        map<int, vector<pi>> mp;
        
        for(int o = 0; o < rows;o++) {
            int src = times[o][0];
            int dest = times[o][1];
            int time = times[o][2];
            mp[src].push_back(make_pair(dest, time));
        }

        priority_queue<pi, vector<pi>, greater<pi>> pq; //{time, currentNode}
        pq.push(make_pair(0,k));
        vector<pair<int,bool>> visited(n+1, {0, false});

        while(!pq.empty()) {
            auto current = pq.top(); pq.pop();
            int time = current.first;
            int currentNode = current.second;

            if(visited[currentNode].second)
                continue;

            visited[currentNode] = make_pair(time, true);

            for(auto el : mp[currentNode]) {
                int dest = el.first;
                int newTime = el.second;
                pq.push(make_pair(time+newTime, dest));
            }
        }
        int mx(0);
        for(int o = 1; o <= n;o++) {
            if(!visited[o].second)
                return -1;
            mx = max(mx, visited[o].first);
        }
        return mx;
    }
};

