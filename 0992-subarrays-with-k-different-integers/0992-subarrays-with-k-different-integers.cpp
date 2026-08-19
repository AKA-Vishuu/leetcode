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
        unordered_map<int, int> m;

        while(r<n){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]] == 0){
                    m.erase(nums[l]);
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