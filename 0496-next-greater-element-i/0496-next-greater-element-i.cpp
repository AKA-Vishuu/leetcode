class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> vec(m); // vector of next greater element in nums2;

        int i = m-1;

        stack<int> st;
        while(i>=0){
            while(!(st.empty()) && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()){
                vec[i] = -1;
            }
            else{
                vec[i] = st.top();
            }
            st.push(nums2[i]);
            i--;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(nums1[i]==nums2[j]){
                    nums1[i] = vec[j];
                    break;
                }
            }
        }

        return nums1;

    }
};