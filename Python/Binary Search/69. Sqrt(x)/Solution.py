class Solution:
    def mySqrt(self, x: int) -> int:
        l,r = 0, x;
        while l <= r:
            mid = l + (r-l)//2;
            val = mid * mid;
            if val > x:
                r = mid - 1;
            elif val < x:
                l = mid +1;
            else:
                return mid;
        return r;

