class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> suffix;
        vector<int> prefix;
        unordered_map<int,int> prefmap;
        int sumi=0;
        for(int i=n-1;i>=0;i--){
            sumi+=nums[i];
            suffix.push_back(sumi);
        }
        sumi=0;
        for(int i=0;i<n;i++){
            sumi+=nums[i];
            prefix.push_back(sumi);
            prefmap[sumi]=i;
        }
        if(prefix[n-1]<x){
            return -1;
        }
        reverse(suffix.begin(),suffix.end());
        auto it=prefmap.find(x);
        int temp=0,result=INT_MAX;
        if(it!=prefmap.end()){
            result=min(result,it->second+1);
            // return it->second+1;
        }
        // it=
        for(int i=n-1;i>=0;i--){
            // temp+=nums[i];
            if(suffix[i]==x){
                result=min(result,n-1-i+1);
                // return n-1-i+1;
            }
            if(x-suffix[i]<0){
                break;
            }
            it=prefmap.find(x-suffix[i]);
            if(it!=prefmap.end()){
                result=min(result,it->second+1+n-1-i+1);
                // return it->second+1+n-1-i+1;
            }
            // cout<<i<<"  "<<result<<endl;
        }
        if(result==INT_MAX){
            return  -1;
        }
        return result;
        // return -1;
    }
};