class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.length();

        vector<int> LastIdx(26);
        for(int i=0; i<n; i++){
            LastIdx[s[i]-'a']=i;
        }

        vector<bool> present(26, false);

        string t="";

        for(int i=0; i<n; i++){
            if(present[s[i]-'a']){
                continue;
            }

            while(!(t.empty()) && s[i]<t.back() && LastIdx[t.back()-'a']>i){
                present[t.back()-'a']=false;
                t.pop_back();
            }
            t.push_back(s[i]);
            present[s[i]-'a']=true;
        }
        return t;
    }
};