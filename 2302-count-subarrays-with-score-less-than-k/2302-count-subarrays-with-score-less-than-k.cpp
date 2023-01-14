class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int i=0,j=0,result=0,n=nums.size(),sumi=0;
        while(j<n){
            sumi+=nums[j];
            if(sumi*(j-i+1)<k){
                while(i-1>=0&&(sumi+nums[i-1])*(j-i+2)<k){
                    i--;
                    sumi+=nums[i];
                }
            }
            else{
                while(i<=j&&sumi*(j-i+1)>=k){
                    sumi-=nums[i];
                    i++;
                }
            }
            if(sumi==0){
                // i++;
            }
            else if(sumi<k){
                result+=j-i+1;
            }
            else{
                cout<<"Something is wrong in this case"<<endl;
            }
            j++;
        }
        return result;
    }
};