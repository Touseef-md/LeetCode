class Solution {
public:
    vector<int> LongestIncreasingSubsequence(vector<int>& nums){
        int n= nums.size();
        vector<int> LIS(n,1);
        LIS[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    LIS[i]=max(LIS[i],LIS[j]+1);
                }
            }
            // cout<<"I: "<<i<<"  "<<LIS[i]<<endl;
        }
        return LIS;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> inc = LongestIncreasingSubsequence(nums);
        reverse(nums.begin(),nums.end());
        vector<int> dec = LongestIncreasingSubsequence(nums);
        reverse(dec.begin(), dec.end());
        int n =nums.size();
        int maxi =0, upper = INT_MAX, index ;
        for(int i=0; i<n ;i++){
            if(maxi <= inc[i]+dec[i]-1 && inc[i]!=1 && dec[i]!=1){
                index = i;
                maxi = max(maxi, inc[i]+dec[i]-1);
            }
            // cout<<"INC"<<inc[i]<<"  DEC "<<dec[i]<<"  Maxi: "<<maxi<<endl;
        }
        // cout<<"MAxi is : "<<maxi<<endl;
        return n-maxi;
    }
};