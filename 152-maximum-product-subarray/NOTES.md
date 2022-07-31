Here we are doing almost same as Kadane's algo.
​
We are computing maxPro and minPro with subarrays ending at that particular index, and also computing a global max.
​
**
ERROR**
Here is some error while implementing , is we use this
```
// temp1=maxpro*arr[i];
// temp2=minpro*arr[i];
// maxpro=max(temp1,max(arr[i],temp2));
// minpro=min(temp1,min(arr[i],temp2));
```
then there is no error, but when we use this:
```
maxpro=max(maxpro*arr[i],max(arr[i],minpro*arr[i]));
minpro=min(maxpro*arr[i],min(arr[i],minpro*arr[i]));
```
This gives error, don't know why.