Code for Dense graph will not work here as V^2 reaches 10^8 , also E~=v ,it's a sparse graph.
​
Here ,for sparse code in the last if condition, if we use >= then there is TLE, if we use > the it's good.
<br>
Here the edge case is that while update the distance and pushing the node in the priority_queue, we should not use the = sign i.e. cost * it.second>=dist[it.first] this = sign should not be used, because in this case we could be trapped inside a loop if it.second turns out to be 1.  A->B->A
<br>
Apart from dijkstra , there is another approach for this question i.e. dfs + pruning, although it gives TLE. Pruning can be done with probability, if the current prob<maxProb then return.