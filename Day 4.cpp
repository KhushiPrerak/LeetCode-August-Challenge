class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n==0 || n==INT_MIN) return false;
        
        if(n && (n&(n-1))==0) {
            int count = 0;
            while(n>1) {
                count++;
                n=n>>1;
            }
            if(count%2==0) return true;
            return false;
        }
        return false;
    }
};
