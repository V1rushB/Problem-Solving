class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a(nums.size());
        vector<pair<int,int>> d(a);
        transform(nums.begin(), nums.end(), d.begin(), [n = 0](int value) mutable {
            return make_pair(value, n++);
        });
        sort(d.begin(), d.end());
        int l(0),r(a-1);
        while(r > l) {
            if(d[l].first + d[r].first == target) {
                int left = min(d[l].second,d[r].second);
                int right = max(d[l].second,d[r].second);
                return vector<int>{left,right};
            }

            else if(d[l].first + d[r].first < target) {
                l++;
            } else {
                r--;
            }
        }
    }
};

