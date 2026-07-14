class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();

        int count =0;
        
        string str="";
        int idx=0;
        
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                str += s.substr(idx+1, i-idx-1);
                idx=i+1;
            }
        }
        return str;
    }
};