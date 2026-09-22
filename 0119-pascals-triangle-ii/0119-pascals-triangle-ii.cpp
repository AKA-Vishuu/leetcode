class Solution {
public:
    int nCr(int n, int r){
        if(r>n){
            return 0;
        }

        r = min(r, n-r);

        long long ans = 1;
        for(int i=0; i<r; i++){
            ans = ans*(n-i);
            ans = ans/(i+1);
        }

        return ans;
    }
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        
        vector<int> vec(n+1);

        for(int i=0; i<=n; i++){
            vec[i] = nCr(n, i);
        }

        return vec;

    }
};