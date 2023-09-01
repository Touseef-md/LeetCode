class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),result=0,i=0,maxi=0;
        if(n==1){
            return 0;
        }
        while(i<n){
            int till=i+nums[i];
            result++;
            if(till>=n-1){
                return result;
            }
            int ind;
            while(i<n&&i<=till){
                if(i+nums[i]>maxi){
                    maxi=i+nums[i];
                    ind=i;
                }
                // maxi=max(maxi,i+nums[i]);
                i++;
            }
            if(i==n){
                cout<<"NOT handled"<<endl;
            }
            else{
                i=ind;
            }
            // i++;
        }
        // retu
        //         for(int i=0;i<n;i++){
            
//         }
        return -1;
    }
};