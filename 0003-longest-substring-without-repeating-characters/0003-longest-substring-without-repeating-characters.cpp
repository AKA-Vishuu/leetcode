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

        vector<int> hash(257, -1);

        while(r<n){
            if(hash[s[r]] != (-1)){
                l = max(l, hash[s[r]]+1);
            }
            maxi = max(maxi, r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxi;
    }
};