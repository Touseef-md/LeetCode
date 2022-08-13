class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> ngr(n);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums[i%n])
                st.pop();
            if(st.empty())
                ngr[i%n]=-1;
            else{
                ngr[i%n]=st.top();
            }
            st.push(nums[i%n]);
        }
        return ngr;
    }
};