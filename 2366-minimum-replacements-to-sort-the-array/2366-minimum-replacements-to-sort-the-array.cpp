class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int n=nums.size(),i=n-2,temp=nums[n-1];
        if(n==1){
            return ans;
        }
        while(i>=0){
            if(nums[i]>temp){
                int a=nums[i]/temp;
                int b=nums[i]%temp;
                ans+=(a-1);
                if(nums[i]%temp==0){
                    // temp=nums[i]/temp;
                }
                else{
                    ans++;
                    // long long c=temp*1LL+b;
                    // temp=c/2;
                    temp=nums[i]/(a+1);
                }
            }
            else{
                temp=nums[i];
            }
                i--;
        }
        return ans;
    }
};