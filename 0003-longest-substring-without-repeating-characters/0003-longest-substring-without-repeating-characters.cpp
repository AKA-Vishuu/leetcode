class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        
        if(n==0){
            return 0;
        }

        int count=0;
        int maxi=INT_MIN;
        string t="";
        for(int i=0; i<n; i++){
            int x = t.find(s[i]);
            if(!(t.empty()) && (x<t.length())){
                count -= (x+1);
                t.erase(0, (x+1));
            }
            t.push_back(s[i]);
            count++;
            maxi=max(maxi, count);
        }
        return maxi;
    }
};