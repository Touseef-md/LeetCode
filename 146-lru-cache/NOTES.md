Do it again.<br>
For LRU Cache, we'll use unordered_map<key,Node*> and doubly linked list. We'll store the last recently used at the head at all times and the least recently used at the end.<br>
And the insertion and deletion operation will be in O(1).