class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        int n=nums.size(),k,i=0,j;
        while(i<n){
            if(nums[i]>0)
                break;
            if(i!=0&&nums[i]==nums[i-1]){
                i++;
                continue;
            }
            j=i+1;k=n-1;
            while(j<k){
                // cout<<i<<' '<<j<<" "<<k<<endl;
                int temp=nums[i]+nums[j]+nums[k];
                if(nums[k]<0)
                    break;
                if(temp<0)
                    j++;
                else if(temp>0)
                    k--;
                else{
                    answer.push_back({nums[i],nums[j],nums[k]});
                    while(j<k&&nums[j]==nums[j+1])
                        j++;
                    while(k>j&&nums[k]==nums[k-1])
                        k--;
                    j++;
                    k--;
                }
            }
            i++;
        }
        return answer;
    }
};