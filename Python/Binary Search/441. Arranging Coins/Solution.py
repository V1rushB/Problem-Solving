class Solution:
    def check(self, mid: int, n: int) -> bool:
        return (mid * (mid + 1) // 2) <= n

    def arrangeCoins(self, n: int) -> int:
        l, r, temp = 0, n, -1
        while l <= r:
            mid = l + (r - l) // 2
            if self.check(mid, n):
                l = mid + 1
                temp = mid
            else:
                r = mid - 1
        return temp
