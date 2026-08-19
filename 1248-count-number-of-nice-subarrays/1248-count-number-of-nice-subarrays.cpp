class Solution {
public:
    int numberOfSubarrayswithLessthanorequaltoKoddNumbers(vector<int>& nums, int k){
        int n = nums.size();

        if(k<0){
            return 0;
        }
        int l = 0;
        int r = 0;

        int count = 0;
        int sum = 0;
        while(r<n){
            sum += (nums[r]%2);
            while(sum > k){
                sum -= (nums[l]%2);
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (numberOfSubarrayswithLessthanorequaltoKoddNumbers(nums, k)-numberOfSubarrayswithLessthanorequaltoKoddNumbers(nums, k-1));
    }
};