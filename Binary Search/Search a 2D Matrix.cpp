//problem link: https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        vector<int> d;
        for(int o = 0; o < n;o++)
            for(int i = 0; i < m;i++)
                d.push_back(matrix[o][i]);
        int l(0),r(d.size()-1);
        while(l<=r)
        {
            int mid = (r-l)/2+l;
            if(d[mid] == target)
                return true;
            else if(d[mid] < target)
                l = mid + 1;
            else {
                r = mid - 1;
            }
        }
        return false;
    }
};