typedef pair<int,int> pi;
typedef pair<int,pair<int,int>> pii;
class Solution {
    int rows, cols;

    int getCost(pi sp, pi ep) {
        return abs(sp.first - ep.first) + abs(sp.second - ep.second);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        rows = points.size(), cols = points[0].size();

        map<pi, vector<pii>> mp; // point -> {{cost, {point}}, ....}
        for(int o = 0; o < rows;o++) {
            for(int i = 0; i < rows;i++) {
                if(i==o)
                    continue;
                int x = points[i][0];
                int y = points[i][1];
                pi refpt = make_pair(points[o][0], points[o][1]);
                pi currentpt = make_pair(x,y);
                int cost = getCost(refpt, currentpt);
                mp[refpt].push_back(make_pair(cost, currentpt));
            }
        }

        for(auto el : mp) {
            cout << '(' << el.first.first  << ", " << el.first.second << ") ->";
            for(auto ell : el.second) {
                //{ , { , }}
                cout << '{' << ell.first << ", " << '{' << ell.second.first << ", " << ell.second.second << "}}, ";
            }
            cout << endl;
        }
        pi stPoint = make_pair(points[0][0], points[0][1]);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, stPoint});
        set<pi> st;
        int s(0);
        while(!pq.empty()) {
            int cost = pq.top().first;
            pi currentPoint = pq.top().second;
            pq.pop();
            // wait for visited
            if(st.find(currentPoint) != st.end()) {
                continue;
            }
            cout << currentPoint.first << ' ' << currentPoint.second << endl;
            cout << cost << endl;
            cout << s << endl;
            st.insert(currentPoint);
            s+= cost;

            if(st.size() == rows)
                break;

            for(auto el : mp[currentPoint]) {
                int newCost = el.first;
                pi newPoint = el.second;
                pq.push({newCost, newPoint});
            }
        } 
        return s;
    }
};

