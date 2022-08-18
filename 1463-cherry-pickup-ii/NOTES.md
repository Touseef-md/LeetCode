**DO IT AGAIN**
<br>
**MISTAKE**
<br>
Initially I was doing by moving one person at a time, on visualizing there is isn't much difference with this, my recursive solution was working but on memoization it was giving wrong answer.
<br>
The reason was that when I was moving one person from that cell I was storing it's value and overwriting it with 0.My dp state was dp[i][j][k][l] which was storing the max cherries if the 2 persons were on i,j and k,l. Now suppose the second person now comes to that cell from where first person passed through then the dp state will not be what we thought. In this situation the dp state will now store what is the max cherries if the 2 person starts from i,j and k,l with the new updated grid and not the original one and we don't want that.
<br>