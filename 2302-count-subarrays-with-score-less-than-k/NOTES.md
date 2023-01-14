Approach:Find the no. of subarrays ending at a specific index j.
<br>
Use the i index to do so,if sum*size till now including i and j is less than k decrease i, otherwise increase i.
<br>
Basically I'm searching the correct length of the subaray linearly , some also have done by using binary search similarly.
T.C: O(N)
S.C:O(1)
For more similar sliding window problems:
https://leetcode.com/problems/count-subarrays-with-score-less-than-k/discuss/2138951/JavaC%2B%2BPython-Sliding-Window