class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                s.insert(nums[j]^nums[k]);
            }
        }

        unordered_set<int> s2;
        for(int i=0; i<n; i++){
            for(auto it: s){
                s2.insert(nums[i]^it);
            }
        }
        int count=0;
        for(auto k: s2){
            count++;
        }
        return count;
    }
};