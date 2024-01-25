class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        s = 0;
        for x in nums:
            s ^= x;
        return s;
        
        
