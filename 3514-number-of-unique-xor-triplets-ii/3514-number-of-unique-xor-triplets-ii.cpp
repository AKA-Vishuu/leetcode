class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        
        int mx=0;
        for(int i=0; i<n; i++){
            mx=max(mx, nums[i]);
        }

        int u=1; //Unique Element Till n
        while(u<=mx){
            u=u<<1;
        }

        vector<int> twoPair(u);
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                twoPair[nums[i]^nums[j]]=1;
            }
        }

        vector<int> ans(u);
        for(int i=0; i<u; i++){
            if(twoPair[i]==0){
                continue;
            }

            for(int j=0; j<n; j++){
                ans[nums[j]^i]=1;
            }
        }

        int count=0;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]){
                count++;
            }
        }

        return count;
    }
};