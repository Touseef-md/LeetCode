Took too much time to solve this easy problem.DO AGAIN FAST.
<br>
First made the logic with simply doing the level order traversal, by using map<int,vector<int>> this would store the number in the vertical order according to the horizontal axis.
<br>
**MISTAKE:**
<br>
This will not take this into picture that if we have x and y coordinates of 2 nodes same then we need to store them in sorted order.
<br>
First thought that I will take the level at which the node is and check if the level and the number of nodes of this particular x have nodes >=level or not , but this will not work as if we have at a particular x more than 2 nodes at each level then the calculation will not work.
<br>
**CORRECT APPROACH:**
<br>
I stored the x,y and the value at that coordinate of each node in vector<vector<int>> v then sorted the vector accordingly.
<br>