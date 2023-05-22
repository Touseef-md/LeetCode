I was not able to think that how to find the shortest distance between the two islands.
<br>
Saw the SOLUTION, If we think graphically it will seem that one island will grow 1 step in every direction around the neighour and this will correspond to 1 distance to reach the other island. So we will basically do the bfs of 1 island untill we find the second island. We will mark cells of both the islands with different colours.
<br>
Also while writing the bfs I made a mistake I did not consider for the already visited nodes as they might be pushed in the queue again and again.