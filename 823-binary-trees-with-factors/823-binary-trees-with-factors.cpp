class Solution {
public:
    int m=1000000007;
    unordered_map<int,int> dp;
    unordered_map<int,int> st;
    int count_BST(vector<int>& arr,int i){
        if(i>=arr.size())
            return 0;
        auto stored_ans=dp.find(arr[i]);
        if(stored_ans!=dp.end())
            return stored_ans->second;
        long long int count=1;
        for(int j=0;j<arr.size();j++){
            if(arr[i]%arr[j]==0){
                long long int a=1,b=1;
                auto it=st.find(arr[i]/arr[j]);
                if(it!=st.end()){
                    a*=count_BST(arr,it->second);
                    a=a%m;
                    b*=count_BST(arr,j);
                    b=b%m;
                    // cout<<a<<" A   B "<<b<<endl;
                    count=count+((a*b)%m);
                    count%=m;
                }
            }
        }
        return dp[arr[i]]=count%m;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++)
            st[arr[i]]=i;
        for(int i=0;i<arr.size();i++){
            count+=count_BST(arr,i);
            count%=m;
            // cout<<i<<"  "<<count<<endl;
        }
        return count;
    }
};