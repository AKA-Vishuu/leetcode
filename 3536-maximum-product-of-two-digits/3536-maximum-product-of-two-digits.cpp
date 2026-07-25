class Solution {
public:
    int maxProduct(int n) {
        int f=INT_MIN;
        int s=INT_MIN;

        int m=n;
        while(m){
            int rem = m%10;
            if(rem>=f){
                s=f;
                f=rem;
            }
            else if(rem>s){
                s=rem;
            }
            m=m/10;
        }

        return f*s;
    }
};