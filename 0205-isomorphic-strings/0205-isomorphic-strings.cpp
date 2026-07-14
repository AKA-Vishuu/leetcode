class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int freq1[256]={0};
        int freq2[256]={0};

        for(int i=0; i<s.length(); i++){
            if(freq1[s[i]]==freq2[t[i]]){
                freq1[s[i]]=i+1;
                freq2[t[i]]=i+1;
            }
            else{
                return false;
            }
        }
        return true;
    }
};