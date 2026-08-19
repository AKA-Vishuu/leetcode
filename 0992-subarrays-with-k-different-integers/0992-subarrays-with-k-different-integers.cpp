class Solution {
public:
    int function(vector<int>& nums, int k){
        int n = nums.size();

        if(k<=0){
            return 0;
        }
        
        int l = 0;
        int r = 0;

        int count = 0;
        vector<int> arr(n+1);
        int distinct_count = 0;

        while(r<n){
            if(arr[nums[r]] == 0){
                distinct_count++;
            }
            arr[nums[r]]++;
            while(distinct_count > k){
                arr[nums[l]]--;
                if(arr[nums[l]] == 0){
                    distinct_count--;
                }
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (function(nums, k)-function(nums, (k-1)));
    }
};