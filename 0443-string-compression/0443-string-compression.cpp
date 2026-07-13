class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int count=1;
        string str="";
        for(int i=0; i<n-1; i++){
            if(chars[i]==chars[i+1]){
                count++;
            }
            else{
                if(count>1){
                    str += chars[i] + to_string(count);
                }
                else{
                    str += chars[i];
                }
                count=1;
            }
        }
        if(count>1){
            str += chars[n-1] + to_string(count);
        }
        else{
            str += chars[n-1];
        }

        for(int i=0; i<str.length(); i++){
            chars[i]=str[i];
        }

        return str.length();
    }
};