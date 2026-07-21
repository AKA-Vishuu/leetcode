class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                cnt++;
            }
        }

        vector<int> vec;
        int count=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                count++;
            }
            else{
                if(count>0){
                    vec.push_back(count);
                }
                count=0;
            }
        }
        if(count>0){
            vec.push_back(count);
        }

        if(vec.size()<=1){
            return cnt;
        }

        int maxi=INT_MIN;
        for(int i=0; i<vec.size()-1; i++){
            maxi=max(maxi, (vec[i]+vec[i+1]));
        }
        return maxi+cnt;

    }
};