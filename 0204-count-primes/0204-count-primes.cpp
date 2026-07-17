class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1){
            return 0;
        }
        vector<bool> vec(n, true);
        vec[0]=false;
        vec[1]=false;

        for(int i=2; i*i<=n; i++){
            if(vec[i]){
                for(int j=2*i; j<n; j+=i){
                    vec[j]=false;
                }
            }
        }

        int count=0;
        for(int i=0; i<n; i++){
            if(vec[i]){
                count++;
            }
        }
        return count;
    }
};