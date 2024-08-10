auto compare = [](const pair<int,int> &n1, const pair<int,int> &n2) {
    return n1.second > n2.second;
};

class Solution {
private:
    int rows, cols;
    vector<string> ans;

    void dfs(pair<int,int> node, map<string, bool> &visited, map<string, priority_queue<pair<string,char>>, vector<pair<string,char>>, decltype(compare)> &mp) {
        string ticket = node.first;
        visited[node.first] = true;

        auto &children = mp[node.first];

        while (!children.empty()) {
            auto current = children.top(); children.pop();

            if (!visited[current.first]) {
                dfs(current, visited, mp);
            }
        }
        ans.push_back(ticket);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        rows = tickets.size(); cols = tickets[0].size();

        map<string, priority_queue<pair<string,char>, vector<pair<string,char>>, decltype(compare)>> mp;
        map<string, bool> visited;

        for (int o = 0; o < rows; o++) {
            Node from(tickets[o][0], tickets[o][0][0]);
            Node to(tickets[o][1], tickets[o][1][0]);
            mp[from.ticket].push(to);
        }

        dfs(Node("JFK", 'J'), visited, mp);
        return ans;
    }
};

