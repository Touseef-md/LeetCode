class Solution {
public:
    vector<int> NGR(vector<int>& height){
        stack<int> st;
        int n=height.size();
        vector<int> ngr(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&height[st.top()]<height[i])
                st.pop();
            if(st.empty())
                ngr[i]=-1;
            else
                ngr[i]=st.top();
            st.push(i);
        }
        return ngr;
    }
    vector<int> NGL(vector<int>& height){
        stack<int> st;
        int n=height.size();
        vector<int> ngl(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&height[st.top()]<=height[i])
                st.pop();
            if(st.empty())
                ngl[i]=-1;
            else
                ngl[i]=st.top();
            st.push(i);
        }
        return ngl;
    }
    int trap(vector<int>& height) {
        vector<int> ngr=NGR(height);
        vector<int> ngl=NGL(height);
        int water=0,n=height.size();
        for(int i=0;i<n;i++){
            if(ngl[i]==-1||ngr[i]==-1)
                continue;
            water+=(min(height[ngr[i]],height[ngl[i]])-height[i])*(ngr[i]-ngl[i]-1);
        }
        return water;
    }
};