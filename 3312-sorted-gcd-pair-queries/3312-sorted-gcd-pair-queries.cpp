class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            maxi=max(maxi, nums[i]);
        }

        vector<int> divisorFreq(maxi+1);
        for(int i=0; i<n; i++){
            // divisor of nums[i];
            for(int j=1; j*j<=nums[i]; j++){
                if(nums[i]%j==0){
                    divisorFreq[j]++;
                    if((nums[i]/j)!=j){
                        divisorFreq[nums[i]/j]++;
                    }
                }
            }
        }

        vector<long long> PairsWithGCD(maxi+1);
        
        for(int i=maxi; i>=1; i--){
            long long int count = divisorFreq[i];
            
            // count the pairs;
            PairsWithGCD[i] = (count*(count-1))/2;

            // remove the duple or more counted pairs
            for(int j=2*i; j<=maxi; j+=i){
                PairsWithGCD[i] -= PairsWithGCD[j];
            }
        }

        for(int i=1; i<=maxi; i++){
            PairsWithGCD[i] += PairsWithGCD[i-1];
        }

        vector<int> temp(queries.size());
        for(int i=0; i<temp.size(); i++){
            temp[i]=upper_bound(PairsWithGCD.begin(), PairsWithGCD.end(), queries[i])-PairsWithGCD.begin();
        }

        return temp;

    }
};