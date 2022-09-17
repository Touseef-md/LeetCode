Do it again, took too much time.
<br>
AT the very first time, not able to formulate the logic, not able to figure out that how we can build this kind of logic in the given time constraint.
<br>
LOGIC: Store each string and their index in a map. Then go through each word, let the word be made of many (prefix +suffix)s, these can be obtained with for loop. We need to check
<br>
1) If reverse of prefix is available in map or not(with index other than that of current word) and suffix is palindrome or not.
2) If reverse of suffix is availeble in map or not(with index other than that of current word) and suffix is palindrome or not.
<br>
This logic gives **TLE** T.C: O(n by k^2)
<br>
CORRECT LOGIC: to use trie