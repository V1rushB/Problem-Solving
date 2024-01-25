class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort();
        mx = -1;
        ans = [];
        for x in range(len(nums)-2):
            ans.append(abs(nums[x]-nums[x+1]));
        ans.sort();
        for x in range(p*2-1):
            mx = max(mx,ans[x]);

        return mx;
