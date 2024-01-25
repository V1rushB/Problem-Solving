class Solution:
    def bs(self,val: int, potions: List[int], success: int):
        l,r,temp = 0, len(potions)-1,-1;
        while l <= r:
            mid = l + (r-l)//2;
            if potions[mid] * val >= success:
                temp = mid;
                r = mid - 1;
            else:
                l = mid + 1; 
        return temp;
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort();
        ans = [];
        for x in spells:
            val = self.bs(x,potions,success);
            ans.append((len(potions) - val) * (val!=-1));
        return ans;
