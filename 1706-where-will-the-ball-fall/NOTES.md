SOlved using DFS,<br>
but this can also be solved using dp.<br>
**Approach 2: Dynamic Programming**<br>
What information is required to compute the result for a ball positioned at a cell(row,column) ?<br>
The answer is that to compute the result for the current cell, we require the values of the next column in row+1. <br>
If we find the result for every cell of grid in a bottom up fashion, that is, starting from the last row to the first row, we will always have the result of row+1 while computing the result for row.<br>
**Approach 3: Optimised dynamic programming**<br>
optimise space further