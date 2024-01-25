class Solution:
    def fixString(self, s: str) -> str:
        return ''.join([char.lower() if char.isalpha() else char for char in s if char.isalpha() or char.isdigit()]);

    def isPalindrome(self, s: str) -> bool:
        string = self.fixString(s);
        l,r = 0,len(string)-1;
        while(l<=r):
            if string[l] != string[r]:
                return False;
            else:
                l+=1; r-=1;
        return True;
