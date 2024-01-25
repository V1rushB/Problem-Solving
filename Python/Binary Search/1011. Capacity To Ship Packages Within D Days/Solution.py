class Solution:
    def check(self, weights: List[int],val: int, days: int):
        s,d = 0,0;
        for x in weights:
            if x > val:
                return False;
            s+=x;
            if s >= val:
                d+=1;
                s = x * (s != val);
        return days > d;



    def shipWithinDays(self, weights: List[int], days: int) -> int:
        l,r,temp = 0, sum(weights),0;
        while l <= r:
            mid = l + (r-l)//2;
            if(self.check(weights, mid,days)):
                r = mid - 1;
                temp = mid;
            else:
                l = mid + 1;
        return temp; 
                


