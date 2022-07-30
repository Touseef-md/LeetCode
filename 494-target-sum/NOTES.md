**NOT ABLE TO DO FIRST TIME**
<br>
**MISTAKE:**
I was not considering the fact that 0 could also be a possible element in the array.
​
<br>
**HOW TO RESOLVE**
<br>
X+Y=S
<br>
X-Y=T
<br>
First for finding the subset having the sum=X, I considered that there are no zeroes in the array which is equivalent of thinking that all zeroes are on the subset Y. Then I get the answer of the above dp problem.
<br>
Now the result obtained is not complete as we didn't considered any zero to lie in the X subset.
Since each zero can come in the X subset and if we see in the actual question sign given to one zero is independent of  the other which means that while moving zeros from subset Y to subset X which zero is sent also matter i.e. order has importance .
<br>
Therefore till now we have calculated the number of subsets which sum to X without any zero now number of subsets having sum X and having only 1 zero will be ans+ans*(nC1) where n is the count of zeros.
<br>
Similarly for 2 zeros we'll have ans+ ans*(nC1)+ans*(nC2)+...
<br>
Therefore the final answer would be ans+ans*(2^n-1)
