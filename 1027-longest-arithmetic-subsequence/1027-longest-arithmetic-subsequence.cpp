class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int mini=INT_MAX,maxi=INT_MIN,flag=0;
        int ans=0;
        // vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        for(int diff=mini-maxi;diff<=maxi-mini;diff++){
            mp.clear();
            // dp.clear();
            // dp.resize(n,0);
            flag=0;
            for(int i=0;i<n;i++){
                auto it=mp.find(nums[i]-diff);
                if(it==mp.end()){
                    mp[nums[i]]=0;
                    continue;
                }
                else{
                    flag=1;
                    mp[nums[i]]=it->second+1;
                }
            }
            for(auto it=mp.begin();it!=mp.end();it++){
                ans=max(ans,it->second);
            }
            // if(flag==0){
            //     mp[nums[i]]=0;
            // }
        }
        return ans+1;
    }
};