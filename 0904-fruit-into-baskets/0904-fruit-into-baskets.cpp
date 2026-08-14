class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int l = 0;
        int r = 0;

        int maxlength = 0;

        unordered_map<int, int> m; // <num, freq>

        while(r<n){
            m[fruits[r]]++;
            if(m.size()>2){
                if(m[fruits[l]]==1){
                    m.erase(fruits[l]);
                }
                else{
                    m[fruits[l]]--;
                }
                l++;
            }
            maxlength = max(maxlength, (r-l+1));
            r++;
        }
        return maxlength;
    }
};