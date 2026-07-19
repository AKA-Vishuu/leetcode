class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();

        vector<int> lastidx(26);
        for(int i=0; i<n; i++){
            lastidx[s[i]-'a']=i;
        }

        vector<bool> present(26, false);

        string str="";
        for(int i=0; i<n; i++){
            if(present[s[i]-'a']){
                continue;
            }

            while(!(str.empty()) && str.back()>s[i] && lastidx[str.back()-'a']>i){
                present[str.back()-'a']=false;
                str.pop_back();
            }
            str.push_back(s[i]);
            present[s[i]-'a']=true;
        }

        return str;
    }
};