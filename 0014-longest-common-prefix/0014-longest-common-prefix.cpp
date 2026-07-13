class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();

        string s = strs[0];

        int idx=-1;
        for(int i=0; i<s.length(); i++){
            for(int j=1; j<n; j++){
                if(strs[j][i]!=s[i]){
                    idx=i;
                    break;
                }
            }
            if(idx!=(-1)){
                break;
            }
        }

        return s.substr(0, idx);
    }
};