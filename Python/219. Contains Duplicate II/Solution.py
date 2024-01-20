class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        hash = {};
        for o in range(len(nums)):
            if nums[o] in hash:
                if((o - hash[nums[o]]) <= k):
                    return True;

            hash[nums[o]] = o;
        return False;
                
            
