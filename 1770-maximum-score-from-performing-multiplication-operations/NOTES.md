**Previous Learning:**
<br>
**I learned that try greedy before thinking about dp**. So according to the sample test cases given I was thinking whether greedy was correct or not. It turned out to be incorrect with these examples:
<br>
`multipliers:[-10,-5], nums:[-5,-5,-3,-2,7,1]`
With this example we can see that greedy will fail.
<br>
**MISTAKE**
<br>
Logic was correct but memoization was not that correct , I was memoizing the dp with dp[i][j] but i,j and k are state variables determinig a particular state of a subproblem and since i,j and k are mathematically related as right=len(nums)-1-(m-k-left), we can reduce the 3D dp problem to 2D dp as the 3 state variables are related to each other.
<br>
So we need to memoize using dp[i][k], solution still not accepted with this because of memory limit exceeded **Don't know why?**
<br>
Same solution with recursive solution is giving TLE but with iterative approach accepts.