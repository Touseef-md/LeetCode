class Solution {
public:
    // binSearch(vector<int>& arr,int i,)
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0,j=arr.size()-1,n=arr.size(),mid,ans;
        while(i<=j){
            mid=i+(j-i)/2;
            if(mid-1>=0&&mid+1<n&&arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
                return mid;
            else if(mid-1>=0&&arr[mid]>arr[mid-1]){
                ans=mid;
                i=mid+1;
            }
            else if(mid-1>=0&&arr[mid]<=arr[mid-1]){
                ans=mid;
                j=mid-1;
            }
            else if(mid+1<n&&arr[mid]>arr[mid+1]){
                ans=mid;
                j=mid-1;
            }
            else if(mid+1<n&&arr[mid]<=arr[mid+1]){
                ans=mid;
                i=mid+1;
            }
        }
        return ans;
    }
};