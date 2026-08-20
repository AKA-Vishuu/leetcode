class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        int l = 0;
        int r = 0;

        int hash[256] = {0};

        for(int i=0; i<m; i++){
            hash[t[i]]++;
        }

        int count = 0;
        int minLength = INT_MAX;
        int starting_index = -1;

        while(r<n){
            if(hash[s[r]]>0){
                count++;
            }
            hash[s[r]]--;
            while(count == m){
                if(minLength > (r-l+1)){
                    minLength = (r-l+1);
                    starting_index = l;
                }

                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count--;
                }
                l++;
            }
            r++;
        }
        if(starting_index == -1){
            return "";
        }
        else{
            return s.substr(starting_index, minLength);
        }
    }
};