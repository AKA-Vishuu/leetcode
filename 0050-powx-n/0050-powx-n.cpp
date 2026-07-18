class Solution {
public:
    double power(double x, int n){
        if(n==0){
            return 1;
        }

        long long int N=n;
        if(n<0){
            x=1/x;
            N=-N;
        }
        
        if(N%2==0){
            double temp=power(x, N/2);
            return temp*temp;
        }
        else{
            double temp=power(x, N/2);
            return x*temp*temp;
        }
    }
    double myPow(double x, int n) {
        return power(x, n);
    }
};