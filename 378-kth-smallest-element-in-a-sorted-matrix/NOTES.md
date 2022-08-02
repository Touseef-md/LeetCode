**Took way too time to build the logic in S.C.:O(n)**
<br>
**Forgot how to use priority_queue in this question. Already done this question on simple array.**
<br>
**Solution**
<br>
**Approach 1: Using Max-Heap**
<br>
Iterate through each and every element and push k+1 elements in the priority_queue and always pop the max element from the priority_queue, this will ensure that we'll have k smallest elements in the priority_queue.
<br>
There is also a edge case, see the code.
<br>
**Approach 2: Using Min-Heap**
<br>
* Since each of the rows in matrix are already sorted, we can understand the problem as finding the kth smallest element from amongst M sorted rows.
<br>
* We start the pointers to point to the beginning of each rows, then we iterate k times, for each time ith, the top of the minHeap is the ith smallest element in the matrix. We pop the top from the minHeap then add the next element which has the same row with that top to the minHeap.
<br>
**Approach 3:Using Binary Seach**
​