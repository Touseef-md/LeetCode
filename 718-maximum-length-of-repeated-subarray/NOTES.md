This question is same as Longest common substring.
<br>
**MISTAKE:**
<br>
Got one thing wrong in the logic that when we have nums1[i]==nums2[j], then we have to return 1+fun(nums1,nums2,i-1,j-1), with this we are neglecting the case when it might happen that the character at i th index matches with some other j index which would give the max lenght of the subarray. But as we move on with i-1,j-1 other possibilites with this i are neglected.