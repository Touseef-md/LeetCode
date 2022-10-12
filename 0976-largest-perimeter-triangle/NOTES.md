**NOT ABLE TO SOLVE, NOT ABLE TO GET THE LOGIC FOR THE CORRESPONDING TIME COMPLEXITY**
<br>
**My logic:** First I'll do the binary search on the answer i.e. the perimeter and then I'll check if a triplet exist such that x+y+z==p. MY logic failed because I'm not able to form the condition that if I'm not able to find the triplet then what should I do, whether I should move my z to the right or to the left i.e. which search space should I neglect because I'm doing binary search on the z also. Time complexity of my logic is :O(log(P)Nlog(N))
<br>
Saw the solution..
<br>
Logic was too simple, just have to sort. Then just check if the consecutive triplets form a valid triangle or not.<br>
No case would exist such that maximum perimeter exist and that will not be a consecutive triplet because if a triplet exist other than a consecutive triplet then we can always take the element that is greater than that element as the array is sorted.<br>
If the condition ( that a+b>c and a,b,c are consecutive triplets) is satisfied then b+c>a and c+a>b is automatically satisfied. But the point is, is it the **sufficient condition.**