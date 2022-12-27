class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int mid,n=price.size(),l=0,r=price[n-1];
        int result=0;
        while(l<=r){
            mid=l+(r-l)/2;
            int i=1,count=1,prev=price[0];
            while(i<price.size()){
                if(price[i]-prev>=mid){
                    count++;
                    prev=price[i];
                }
                if(count==k)
                    break;
                i++;
            }
            if(count==k){
                result=max(result,mid);
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return result;
    }
};