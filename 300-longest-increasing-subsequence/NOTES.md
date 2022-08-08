There is an O(NlogN) Solution to this also.
<br>
In the First attempt I've done with simple DP aaproach i.e with T.C: O(n^2) and S.C:O(n)
<br>
This is the second attempt.Now I've done in T.C:O(NlogN)
<br>
**Approach** is that we are using the same space and overwriting the values of the same array instead of creating different sub sequences, because we need not to find the LIS , we've to find only the length of the LIS.
<br>
**MISTAKE**
<br>
In the binary search area, if the tail[mid]==nums[i], then we need to update the upper_b and we need to move in the **left subarray** and not the right.
<br>
Beacuse the if we move to the right subarray and then update the upperbound then we'll have two consecutive indices having the same value,  then this will be incorrect beacuse next index should always be greater in the tail array because we're making strictly increasing subsequence.