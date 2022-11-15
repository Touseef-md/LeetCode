Do it again.<br>
Nice approach<br>
**Approach:** Divide and COnquer technique is applied. Every time halving the total number of nodes to be searched.<br>
Handle the edge case of Complete Binary Tree having **all levels all nodes**.<br>
To get the number of leaf nodes, do [2^(height)-1]-[2^(height-1)-1].
So to get the number of leaf nodes I did this:<br>
1. If going to left subtree copy the same number of nodes.<br>
2. If going to right subtree calculate the leaf nodes of the left subtree, add them to the previous coming leaf nodes from parent and pass to the right subtree.<br>