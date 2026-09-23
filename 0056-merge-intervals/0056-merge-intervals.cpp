class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        vector<vector<int>> vec;

        for(int i=0; i<n; i++){
            if(vec.empty()){
                vec.push_back({intervals[i][0], intervals[i][1]});
            }
            else if(vec.back()[1]<intervals[i][0]){
                vec.push_back({intervals[i][0], intervals[i][1]});
                continue;
            }
            else{
                if(vec.back()[1]<intervals[i][1]){
                    int temp = vec.back()[0];
                    vec.pop_back();
                    vec.push_back({temp, intervals[i][1]});
                }
                else{
                    continue;
                }
            }
        }
        return vec;

    }
};