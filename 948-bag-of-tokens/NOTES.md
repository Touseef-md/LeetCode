MISTAKE:
<br>
Initially I was thinking to solve using dp, it will also work but this can easily be solved using the greedy approach.
<br>
Another mistake forgot to handle the corener case that if we have the first element greater than the power then we cannot take any element from the tokens but I was facing down the last token, thus reducing the score. Score was getting negative.
<br>
Try to implement greedy before applying dp.