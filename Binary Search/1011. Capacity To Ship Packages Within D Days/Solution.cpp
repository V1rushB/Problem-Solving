class Solution {
public:

    bool isValid(vector<int> &d, int days, int target) {
        int s(0);
        for(int o = 0; o < d.size();o++) {
            if(!days) {
                return false;   
            }
            if(s + d[o] <= target) {
                s+=d[o];
            } else {
                days--;
                if(d[o] <= target) {
                    s = d[o];
                } else {
                    return false;
                }
            }
        }
        return days;
    }

    int binarys(vector<int> &d, int days, int uB) {
        int l(1), r(uB),temp(0);
        while(l<=r) {
            int mid = l + (r-l)/2;
            cout << "mid: " << mid << endl;
            if(isValid(d,days,mid)) {
                temp = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return temp;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int uB  = std::accumulate(weights.begin(),weights.end(),0);
        return binarys(weights, days, uB);
    }
};
