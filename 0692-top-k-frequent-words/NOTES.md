I made a mistake, didn't understood the question correctly. <br>
I cannot take only k elements from the priority queue because it may occur that all of them have the same frequency , in that case I'll be removing the options from which I've to sort them lexicographically.<br>
So I can k elements only when I've sorted them in the lexicographically order.
<br>
Time Complexity is:O(NlogN),space complexiyt is:O(N)
<br>
**Improved time complexity**<br>
IN order to do this in O(NlogK), I've to eliminate the elements in the priority queue, but earlier I was not able to remove them because it was not lexicographically sorted in the priority queue. So I've used a comparator function in the priority queue.<br>
Now the time complexity is : O(N logK) and space complexity :O(N)