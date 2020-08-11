class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        long pow = 1;
        long ans = 0;
        for(int i=n-1;i>=0;i--){ 
            ans = ans + (s[i]-'A'+1)*pow;
            pow*=26;
        }
        return (int)ans;
    }
};
