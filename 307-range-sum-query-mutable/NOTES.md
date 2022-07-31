.# My Approach
​
I took a vector and initialize the vector in the constructor .
* For Update used index to  directly update.
* For sum , I used Divide and  Conquer technique to calculate sum, as in each level T.C:O(1) as the add operation of the left and right part will only take constant time.So the time complexity for the sumRange become O(logN).
​
**MISTAKE**
Time complexity is not O(logN) but O(N) because making the tree will cost O(N), ans what I think is that in merge sort the actual time complexity is O(N+NlogN), so we didn't see that N.
​
**APPROACHES**
There are total 3 approaches :
1) Naive one, which I think is what I've done.
2) Sqrt Decomposition (NOT READ NOW).
3) Segment Tree(Learned and implemented first time)