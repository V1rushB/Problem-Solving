class Solution {
public:

    bool isValid(const vector<int> &d, const int h, const long long target) {
        long long ctr(0);
        for(long long o = 0; o < d.size();o++) {
            long long div = d[o]/target + (bool(d[o]%target));
            ctr+=div;
        }
        return ctr <= h;
    }

    int binarys(const vector<int> &d, const long long h, const long long upperBound) {
        long long l(1),r(upperBound),temp(-1);
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(isValid(d, h, mid)) {
                temp = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return temp;
    }

    int minEatingSpeed(vector<int>& piles, long long h) {
        long long upperBound = *max_element(piles.begin(), piles.end());
        return binarys(piles, h, upperBound);
    }
};

