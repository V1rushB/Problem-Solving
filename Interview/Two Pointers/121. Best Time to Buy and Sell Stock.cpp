class Solution {
    public: 
        int maxProfix(vector<int> &prices) {
            int l(0), r(0), mx(0);
            while(r < prices.size()) {
                mx = max(mx, prices[r] - prices[l]);
                r++;
                if(prices[r] < prices[l]) {
                    l = r++;
                    if(r >= prices.size()) {
                        break;
                    } 
                }

            }
            return mx;
        }
};
