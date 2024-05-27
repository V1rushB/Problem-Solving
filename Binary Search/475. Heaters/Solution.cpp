class Solution {
public:

    bool isValid(vector<int> &h, vector<int> &d, int dist) {

        int o(0),i(0);
        while(i < h.size() && o < d.size()) {
            if(abs(h[i] - d[o]) <= dist) {
                i++;
            } else {
                o++;
            }
        }
        return o < d.size();
    }

    int binarys(vector<int> &h, vector<int> &d, int upperBound) {
        int l(0),r(upperBound-1),temp(0);
        while(l <= r) {
            int mid = l + (r-l)/2;
            cout << "mid: " << mid << endl; 
            if(isValid(h,d,mid)) {
                temp = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return temp;
    }

    int findRadius(vector<int>& houses, vector<int>& d) {
        int upperBound(0);
        for(int el : houses)
            upperBound = max(upperBound, el);
        for(int el : d)
            upperBound = max(upperBound,el);

        sort(houses.begin(),houses.end());
        sort(d.begin(),d.end());
        return binarys(houses, d, upperBound);
    }
};
