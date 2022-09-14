**MISTAKE :** Took too long to solve such an easy problem, First not read problem sample test case properly, second difficulty due to bitset syntax.
<br>
There is no case mentioned for number of one's equal to 1,so it's answer should be false.
<br>
If we have number of bytes more than 4 then also we should return false.
<br>
Suppose we have to consider 5 bytes and there are no 4 bytes ahead of this first byte.
<br>
2 bytes onwards everything is fine, but for 1 byte we to start with 0 only.
<br>
**Resolve:** In bitset 0 index refers to last position if we consider right to left indexing.