class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=(nums1.size()+nums2.size())/2;
        if(nums1.size()==0&&nums2.size()==0)
            return 0;
        if(nums1.size()==0){
                int x=nums2.size();
            if(nums2.size()%2==0){
                return (nums2[(x-1)/2]+nums2[(x-1)/2+1])/2.0;
            }
            return nums2[x/2];
        }
        if(nums2.size()==0){
                int x=nums1.size();
            if(nums1.size()%2==0){
                return (nums1[(x-1)/2]+nums1[(x-1)/2+1])/2.0;
            }
            return nums1[x/2];
        }
        int l=0,r=n,mid,i,j;
        while(l<=r){
            mid=l+(r-l)/2;
            if(mid>nums1.size()){
                r=mid-1;
                continue;
            }
            if(n-mid>nums2.size()){
                l=mid+1;
                continue;
            }
            i=mid-1;
            j=n-mid-1;
            if(i>=0&&i<nums1.size()){
                if(j+1<nums2.size()&&nums1[i]>nums2[j+1]){
                    r=mid-1;
                }
                else if(j>=0&&j<nums2.size()){
                    if(i+1<nums1.size()&&nums2[j]>nums1[i+1]){
                        l=mid+1;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            else if(j>=0&&j<nums2.size()){
                if(i+1<nums1.size()&&nums2[j]>nums1[i+1]){
                    l=mid+1;
                }
                else
                    break;
            }
            else{
                cout<<"INvalid case "<<endl;
            }
            // if(j>=nums2.size()){
            //     l=mid+1;
            // }
            // // else if(i+1<nums1.size()&&j+1<nums2.size()){
            // //     break;
            // // }
            // else if(j+1<nums2.size()){
            //     if(nums1[i]>nums2[j+1])
            //         r=mid-1;
            //     else 
            //         break;
            // }
            // else if(i+1<nums1.size()){
            //     if(nums2[j]>nums1[i+1])
            //         r=mid-1;
            //     else
            //         break;
            // }
            // else{
            //     break;
            // }

        }
        cout<<"MID"<<mid<<endl;
        int a=(i==-1)?nums2[j]:nums1[i];
        int b=(j==-1)?nums1[i]:nums2[j];
        int c=(i==nums1.size()-1)?nums2[j+1]:nums1[i+1];
        int d=(j==nums2.size()-1)?nums1[i+1]:nums2[j+1];
        int x=nums1.size()+nums2.size(); 
        if(x%2==0){
            return (max(a,b)+min(c,d))/2.0;
        }
        return min(c,d);
        // if(x%2==0){
        //     if(i==-1){ 
        //         return (nums2[j]+min(nums1[i+1],nums2[j+1]))/2.0;
        //     }
        //     else if(j==-1)
        //         return (nums1[i]+min(nums1[i+1],nums2[j+1]))/2.0;
        //     return (max(nums1[i],nums2[j])+min(nums1[i+1],nums2[j+1]))/2.0;
        // }
        // else{
        //     if(i==-1){
        //         return min(nums1[i+1],nums2[j+1]);
        //     }
        //     else if(j==-1){
        //         return min(nums1[i+1],nums2[j+1]);
        //     }
        //     return min(nums1[i+1],nums2[j+1]);
        // }
        return 0;
    }
};