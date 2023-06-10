class Solution {
public:
    bool condition(int& n,int& index,int& maxSum,int& x){
        long long int sumi1=0,sumi2=0;
        if(index-x+1>=0){
            sumi1=index-x+1+(x*1LL*(x+1))/2;
        }
        else{
            sumi1=x*1LL*(index+1)-(index*1LL*(index+1))/2;
        }
        if(index+x-1<=n-1){
            sumi2=(x*1LL*(x+1))/2+n-index-x;
        }
        else{
            sumi2=(n-index)*1LL*x-((n-index)*1LL*(n-index-1))/2;
        }
        if(sumi1>maxSum||sumi2>maxSum)
            return false;
        if(sumi1+(sumi2-x)<=maxSum)
            return true;
        return false;
        // return sumi1+sumi2-x;
    }
    int maxValue(int n, int index, int maxSum) {
        // int total_sum=0;
        // if()
        // return (maxSum+index*index+index-n*index+(n*(n-1))/2)/n;
        int l=1,r=maxSum,mid,result=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(condition(n,index,maxSum,mid)){
                result=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return result;
    }
};