class Solution {
public:
    int colmax(vector<vector<int>>& mat, int col){
        int idx=-1;
        int maxi=INT_MIN;

        for(int i=0; i<mat.size(); i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                idx=i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        if(m==1){
            return {colmax(mat, 0), 0};
        }
        if(mat[colmax(mat, 0)][0]>mat[colmax(mat, 0)][1]){
            return {colmax(mat, 0), 0};
        }

        if(mat[colmax(mat, m-1)][m-1]>mat[colmax(mat, m-1)][m-2]){
            return {colmax(mat, m-1), m-1};
        }

        int low=1;
        int high=m-2;

        while(low<=high){
            int mid=low+((high-low)/2);

            int row=colmax(mat, mid);
            if(mat[row][mid] > mat[row][mid+1] && mat[row][mid] > mat[row][mid-1]){
                return {row, mid};
            }
            else if(mat[row][mid]>mat[row][mid+1]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1, -1};
    }
};