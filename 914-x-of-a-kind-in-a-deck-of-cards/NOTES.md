** I wasn't able to form the correct logic at first, I got the idea step by step after stucking at every wrong answer.**
<br>
**MISTAKE**
<br>
For the case where all elements are same I was doing that if the frequency if odd then 0 otherwise false.
<br>
Counter Example is: [1,1,1,1,1,1,1,1,1] answer should be true.
<br>
​
**RESOLVE**:So we the correct way is, we'll return true if the frequency of that single unique element is greater than 1 otherwise false.
<br>
I'm using euclidean algorithm to find gcd whose time complexity is O(log(min(a,b))).
<br>
T.C of the code :O(N log(min(a,b)))
S.C: O(N)