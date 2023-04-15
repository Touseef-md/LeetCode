Took a lot of time,not able to solve on first go.
<br>
Time complexity was:O(n^2)
<br>
Approach: as values can be negative,
either we select a stone or not select it,
prefix[]={a,a+b,a+b+c,a+b+c+d}
if includingg first i stones , diff= value of first i stones- recursion for next
or diff=prefix[i]-solve(i+1)
if not including first i stones , then diff=recursion for next=solve(i)
(when passing recursion to next step, its mentioned that we have
to add up the value of all previous stones to next one, this
thing is already handle by prefix array )
and ans=max of both cases
dp[i]= ans if we work on first i stones
<br>
Now this automatically handles the case that B's score should be negative and A's score should be positive. prefix[i]-solves always takes the prefix[i] as positive i.e. it assumes that prefix[i] is taken by Alice
<br>
One concern in this approach is that how are we deciding that we are taking optimal choice for both alice and bob, it is because we are taking maximum score for any player and that ensures that we are playing optimally.
<br>
This is the solution reference:https://leetcode.com/problems/stone-game-viii/discuss/1491548/C%2B%2B-EXPLAINED-SOLUTION