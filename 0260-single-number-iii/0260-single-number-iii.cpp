class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();

        long long int XorNums = 0;
        for(int i=0; i<n; i++){
            XorNums ^= nums[i];
        }

        int RightmostSetBit = (XorNums&(XorNums-1))^XorNums;

        int bucket1=0;
        int bucket2=0;

        for(int i=0; i<n; i++){
            if(nums[i]&RightmostSetBit){
                bucket1 ^= nums[i];
            }
            else{
                bucket2 ^= nums[i];
            }
        }

        return {bucket1, bucket2};
    }
};