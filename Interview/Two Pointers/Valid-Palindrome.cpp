class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> d(s.size());
        transform(s.begin(), s.end(), d.begin(), [](char value) {
            if(isalnum(value)) {
                return (char)tolower(value);
            }
            return '\0';
        });

        d.erase(remove(d.begin(),d.end(),'\0'),d.end());
        int l(0),r(d.size()-1);
        while(r > l) {
            if(d[r--] != d[l++])
                return false;
        }
        return true;
    }
};
