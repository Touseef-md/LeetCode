**MISTAKE**
<br>
First I was only considering that the ans would be the present node value + max(left, right),but that is not the case as in the example 1.
<br>
Then I thought that we can see the problem as if we consider present node to be included in my path then what would be my answer considering only the children and the present node and not the parent node as parent and the child relationship would get handled when I will consider parent as my present node.
<br>
Another mistake I made was that I was returning the maximum of the 3 cases and we didn't have to do that because the case in which we are taking the node value+right +left we cannot return this as the ans to the parent because this case implies that parent will not be included in the path.
<br>
**SOLUTION**
<br>
So we need to update the maxi variable at all times and return and ans of only the 2 cases.