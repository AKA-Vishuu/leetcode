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
            vec.push_back(__gcd(nums[i], maxi));
        }

        sort(vec.begin(), vec.end());

        int i=0;
        int j=vec.size()-1;

        long long int ans=0;
        while(i<j){
            ans += __gcd(vec[i], vec[j]);
            i++;
            j--;
        }

        return ans;
    }
};