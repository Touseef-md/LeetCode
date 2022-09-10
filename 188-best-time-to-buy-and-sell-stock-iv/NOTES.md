Was able to do the brutefore quickly, but not able to memoize the code.
<br>
DO IT AGAIN, SAW the SOLUTION.
<br>
In the solution I was thinking if I can replace the dp[i][k][0]=max(a,b) to dp[i][k][1]=max(a,b) then this should not effect the result but this EFFECTS the result because the overlapping subproblem will try to search for dp[i][k][0] but it's ans is stored on dp[i][k][1].
<br>
**MISTAKE:**
<br>
I was thinking that I should not store the result when I didn't buy or sell the stock in the dp but this is not the case because that same state can occur and we can use it's ans. Try to
visualize the dp curve i.e. where we sell the stock that will have a dip and where we didn't sell anything there is curve.
<br>