**MISTAKE:**
<br>
I forgot the corner case: that if two nodes are not connected at first and the query came "a!=b", and after that a query occurs "a==b" then this will go unnoticed.
<br>
**Solution:**
<br>
First I iterated through all the queries and do whatevern needs to be done. I iterated again so that, this time whatever node needs to be connected will get connected and this time nothing would go unnoticed.