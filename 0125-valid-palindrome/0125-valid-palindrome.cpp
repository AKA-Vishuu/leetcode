class Solution {
public:
    bool isAlphaNumeric(char ch){
        if((ch>='0' && ch<='9') || (ch>='A' && ch<='Z') || (ch>='a' && ch<='z')){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int st=0;
        int end=s.length()-1;

        while(st<=end){
            if(!(isAlphaNumeric(s[st]))){
                st++;
                continue;
            }

            if(!(isAlphaNumeric(s[end]))){
                end--;
                continue;
            }

            if(tolower(s[st])==tolower(s[end])){
                st++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};