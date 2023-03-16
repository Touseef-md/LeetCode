NOt able to solve under the constraint time complexity.
<br>
I thought that this is a dp problem, it can be solved as a dp problem (my time complexity was O(n^2) but the real solution is using graphs. Connect the nodes wherever we can jump. Then do the BFS to find the shortest path.
<br>
if(flag[x]==-1) before for loop is not working because in this the node whose all same values index are not pushed ( those which were x+1 or x-1 of some other value) their same value indexes will not enter into the queue.<br>
But if we use mp[arr[x]].clear() with this the nodes having the same value will never enter the queue again. And the one who did not enter will always enter because they were never erased.