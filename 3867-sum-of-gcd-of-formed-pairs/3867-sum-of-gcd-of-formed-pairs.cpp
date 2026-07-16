class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();

        int maxi=INT_MIN;
        vector<int> vec;

        for(int i=0; i<n; i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            nums[i]=__gcd(nums[i], maxi);
        }

        sort(nums.begin(), nums.end());

        int i=0;
        int j=n-1;

        long long int ans=0;
        while(i<j){
            ans += __gcd(nums[i], nums[j]);
            i++;
            j--;
        }

        return ans;
    }
};