class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        
        if(n==0){
            return 0;
        }

        int l = 0;
        int r = 0;

        int maxi = 0;
        unordered_map<char, int> m;

        for(int i=0; i<n; i++){
            if(m.find(s[i]) != m.end()){
                l = max(l, m[s[i]]+1);
            }
            maxi = max(maxi, i-l+1);
            m[s[i]]=i;
        }
        return maxi;
    }
};