class Solution {
public:
    int maxArea(vector<int>& d) {
        int l(0), r = d.size()-1,mx = -1e3+5;
        while(r > l) {
            int area = min(d[l],d[r]) * (r-l);
            // cout << d[r] << ' ' << d[l];
            if(d[l] < d[r])
                l++;
            else {
                r--;
            }
            mx = max(area,mx);
        }
        return mx;
    }
};

