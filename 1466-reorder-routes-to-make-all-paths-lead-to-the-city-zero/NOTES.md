HINT::
1)Broken down to bellman ford, but time complexity is high.
2)So done with dijkstra algo.
​
```
||Breakdown to dijkstra||
```
<br>
Not able to do it SECOND TIME AS WELL.
<br>
**Solution:** Do the bfs or dfs and consider the tree as undirected tree and make the adj_list by marking forward and reverse edge and count accordingly while traversing the tree. <br>
Here one important point to note is that this solution works only because this is a tree i.e., 1->2->3->4->1 this case will never come.
​