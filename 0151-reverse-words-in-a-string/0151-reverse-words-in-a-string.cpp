class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        
        reverse(s.begin(), s.end());

        string word="";
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]!=' '){
                word+=s[i];
            }
            else{
                if(word.length()>0 && i<n){
                    reverse(word.begin(), word.end());
                    ans =ans + " " + word;
                    word="";
                }
            }
        }
        if(word.length()>0){
            reverse(word.begin(), word.end());
            ans = ans + " " + word;
        }
        
        return ans.substr(1);
    }
};