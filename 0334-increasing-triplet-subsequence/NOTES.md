**Problem Faced**
<br>
I got the logic in some time, but got stuck in the implementation. Logic is that I will keep 2 maps one storing the left elements and the other storing the right elements of the current element and I will search for a smaller element in the left map and a greater element in the right map using lower and upper bound.There were many edge cases.
<br>
Cases I have to handle here:
<br>
1. For the left map.
<br>
* When I have a mp.end() in the lowerbound in the left map, If the size of the map is zero then there will be no smaller element, Otherwise found an element.<br>
* If the lowerbound iterator is mp.begin(), then there is no smaller element.<br>
* Otherwise for the left map we found the smaller element.<br>
* And when we are dealing with these cases we also need to update the right map, so that it always contain elements to the right of the current element.<br>
2. For the right map. <br>
* If the upperbound iterator turns out mp.end(), then there is no greater element.
* Otherwise we found a greater element to the right of the current element.
​