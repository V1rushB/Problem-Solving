class Solution:
    def check(self, val: int, piles: List[int],hour: int) -> bool:
        s,h = 0,0;
        for x in piles:
            h+= x//val + bool (x%val);
        return hour >= h;

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l,r,temp = 1, max(piles),0;
        while l <= r:
            mid = l + (r-l)//2;
            if self.check(mid,piles,h):
                temp = mid;
                r = mid - 1;
            else:
                l = mid + 1;
        return temp;

