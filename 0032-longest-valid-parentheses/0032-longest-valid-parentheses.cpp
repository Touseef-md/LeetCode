
vector<vector<int>> validParenthesis(string& s){
    // cout<<"check 1"<<endl;
    stack<pair<char,int>> st;
    // cout<<"check 2"<<endl;
    vector<vector<int>> ans;
    for(int i=0;i<s.length();i++){
        // cout<<i<<endl;
        if(s[i]=='('){
            st.push({'(',i});
        }
        else{
            if(!st.empty()&&st.top().first=='('){
                ans.push_back({st.top().second,i});
                st.pop();
            }
            else{
                st.push({s[i],i});
            }
        }
    }
    return ans;
}
bool comp(vector<int>& a,vector<int>& b){
    if(b[0]<a[0])
        return false;
    return true;
}
class Solution {
public:
    int longestValidParentheses(string s) {
        // cout<<"intervals done"<<endl;
    vector<vector<int>> intervals=validParenthesis(s);  
        // for(auto i:intervals){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
    sort(intervals.begin(),intervals.end(),comp);
        int len=0,start,end=0;
        for(int i=0;i<intervals.size();i++){
            start=intervals[i][0];
            end=intervals[i][1];
            len=max(len,end-start+1);
            while(i+1<intervals.size()){
                if(intervals[i+1][0]<end&&intervals[i+1][1]<end){
                    i++;
                }
                else if(intervals[i+1][0]==end+1){
                    end=max(end,intervals[i+1][1]);
                    i++;
                }
                else{
                    break;
                }
            }
            len=max(len,end-start+1);
        }
        return len;
    }
};