This question is same as Longest common substring.
<br>
**MISTAKE:**
<br>
Got one thing wrong in the logic that when we have nums1[i]==nums2[j], then we have to return 1+fun(nums1,nums2,i-1,j-1), with this we are neglecting the case when it might happen that the character at i th index matches with some other j index which would give the max lenght of the subarray. But as we move on with i-1,j-1 other possibilites with this i are neglected.
<br>
**Learned**
<br>
In the recurcise solution, code is not very clear i.e. I have to call three times when characters at i and j th indexes matches, and 2 times when they don't match.
<br>
But we see in the iterative solution we don't have to do this extra function call, reason is because in the iterative solution we are manually calling every possible i and j as a pair, but in the recursive solution, we need to call explicitly otherwise those particular i,j pair we never be called and those will not contribute in the final answer.