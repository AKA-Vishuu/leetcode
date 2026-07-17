class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = true;
        if((dividend>=0 && divisor<0) || (dividend<0 && divisor>0)){
            sign = false;
        }

        long long int n = (long long)(abs((long long)dividend));
        long long int d = (long long)(abs((long long)divisor));

        long long int ans=0;
        while(n>=d){
            int count=0;
            while(n >= (d*(1LL<<(count+1)))){
                count++;
            }
            ans += (1LL<<count);
            n=n-d*(1LL<<count);
        }
        
        if(sign){
            if(ans>INT_MAX){
                return INT_MAX;
            }
            return ans;
        }
        
        if((-ans)<INT_MIN){
            return INT_MIN;
        }
        return -ans;
    }
};