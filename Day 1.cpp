class Solution {
public:
    bool detectCapitalUse(string word) {
       
        bool foundAtFirst = false;
        
        int count = 0; // count of capital letters 
        if(word[0]>='A' && word[0]<='Z'){
            foundAtFirst = true;
            count=1;
        }
        for(int i=1;i<word.length();i++){
            if(word[i]>='A' && word[i]<='Z'){
                count++;
            }
        }
        
        if(foundAtFirst) {
            if(count == 1 || count == word.length())
                return true;
            return false;
        }
        else {
            if(count!=0)
                return false;
            return true;
        }
        
    }
};
