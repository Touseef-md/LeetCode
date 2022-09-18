class Solution {
public:
    vector<int> NGRight(vector<int>& height){
        vector<int> result;
        stack<pair<int,int>> st;
        for(int i=height.size()-1;i>=0;i--){
            if(st.empty()){
                result.push_back(-1);
            }
            else{
                while(!st.empty()&&height[i]>=st.top().first)
                    st.pop();
                if(st.empty())
                    result.push_back(-1);
                else
                result.push_back(st.top().second);
            }
            st.push({height[i],i});
        }
        reverse(result.begin(),result.end());
        return result;
    } 
    vector<int> NGLeft(vector<int>& height){
        vector<int> result;
        stack<pair<int,int>> st;
        for(int i=0;i<height.size();i++){
            if(st.empty()){
                result.push_back(-1);
            }
            else{
                while(!st.empty()&&height[i]>st.top().first)
                    st.pop();
                if(st.empty())
                    result.push_back(-1);
                else
                    result.push_back(st.top().second);
            }
            st.push({height[i],i});
        }
        return result;
    }
    int trap(vector<int>& height) {
        vector<int> NGR=NGRight(height);
        vector<int> NGL=NGLeft(height);
        int water=0;
        for(int i=0;i<height.size();i++){
            if(NGR[i]==-1||NGL[i]==-1)
                continue;
            water+=(min(height[NGR[i]],height[NGL[i]])-height[i])*(NGR[i]-NGL[i]-1);
            cout<<i<<"  "<<water<<endl;
        }
        return water;
    }
};