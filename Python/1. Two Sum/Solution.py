class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        arr = [];
        for x in range(len(nums)):
           arr.append([nums[x],x]);
        arr = sorted(arr);
        l = 0; r = len(arr) - 1;
        marr = [pair[0] for pair in arr];
        while(l < r):
            if marr[l] + marr[r] > target:
                r-=1;
            elif marr[l] + marr[r] < target:
                l+=1;
            else:
                return [arr[l][1],arr[r][1]];
        return [];
        
