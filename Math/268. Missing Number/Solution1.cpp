class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s(n*(n+1)/2),sum(0);
        for(auto &el : nums) {
            sum+=el;
        }
        return s-sum;
    }
};
