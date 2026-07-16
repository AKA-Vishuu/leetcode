class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();

        int NoOfSubset = (1<<n);

        vector<vector<int>> vec;
        
        for(int i=0; i<NoOfSubset; i++){
            vector<int> subset;
            for(int j=0; j<n; j++){
                if(i&(1<<j)){
                    subset.push_back(nums[j]);
                }
            }
            vec.push_back(subset);
        }

        return vec;
    }
};