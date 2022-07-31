class Solution {
public:
    int maxProduct(vector<int>& arr) {
    // int n = arr.size();
    // long long max = INT_MIN;
    // long long prod = 1;
    // for(int i=0;i<n;i++){
    //     prod = prod * arr[i];
    //        if(prod>max){
    //         max = prod;
    //     }
    //     if(arr[i] == 0){
    //         prod = 1;
    //     }
    // }
    // prod = 1;
    // for(int i=n-1;i>=0;i--){
    //     prod = prod * arr[i];
    //        if(prod>max){
    //         max = prod;
    //     }
    //     if(arr[i] == 0){
    //         prod = 1;
    //     }
    // }
    // return max;
int maxpro=arr[0],minpro=arr[0],result=arr[0],n=arr.size(),temp1,temp2;
for(int i=1;i<n;i++){
    temp1=maxpro*arr[i];
    temp2=minpro*arr[i];
    maxpro=max(temp1,max(arr[i],temp2));
    minpro=min(temp1,min(arr[i],temp2));
    // maxpro=max(maxpro*arr[i],max(arr[i],minpro*arr[i]));
    // minpro=min(maxpro*arr[i],min(arr[i],minpro*arr[i]));
    result=max(result,maxpro);
}
return result;
    }
};