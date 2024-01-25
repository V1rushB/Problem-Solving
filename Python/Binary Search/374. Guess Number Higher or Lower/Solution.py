# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        l,r = 1, n;

        while True:
            mid = l + (r-l)//2;
            x = guess(mid);
            if x == -1:
                r = mid - 1;
            elif x:
                l = mid + 1;
            else:
                return mid;
        
