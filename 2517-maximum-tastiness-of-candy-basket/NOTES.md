Not able to do it at once, although knew that it'll be solved with binary search.
<br>
**DO IT AGAIN**
<br>
**MISTAKE:**  I calculated mid then first I was checking if the difference i.e. (mid) exists in the array or not. If exists then I was calculating how many pairs are greater than this mid. **But I think the mistake is that I was not considering that the diff of a particular pair could be less than the mid**.This is the main mistake. If mid does not exist then I will search both greater and less than mid.