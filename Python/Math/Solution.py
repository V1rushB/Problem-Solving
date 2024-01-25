class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        saven = int (sqrt(num));
        return saven**2 == num;

