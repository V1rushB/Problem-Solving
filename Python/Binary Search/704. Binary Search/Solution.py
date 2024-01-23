class Solution(object):
    def search(self, arr, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l = 0; r = len(arr)-1;
        while(l <= r):
            mid = l + (r - l)/2;
            if arr[mid] > target:
                r = mid - 1;
            elif arr[mid] < target:
                l = mid + 1;
            else: 
                return mid;
        return -1;
