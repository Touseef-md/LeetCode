**MISTAKE:** For finding the pointer in the postorder array for the left subtree I used postorderm[inorder[inroot-1]] but this can be the index of not the extreme right index of the left subtree in postorder array. <br>
So i have to use maximum of the indexes from in inorder array to find the largest index in the postorder subarray for the left subtree.
<br>
Could solve with my code saw a discussion, approach was similar but his code was better (TC).