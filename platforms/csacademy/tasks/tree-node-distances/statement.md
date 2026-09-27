# Tree Node Distances

**Time Limit:** `7500 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/tree-node-distances/](https://csacademy.com/contest/archive/task/tree-node-distances/)  

---

The interactor has a rooted tree and you are given two pointers $A$ and $B$ that initially point to two distinct nodes. Your should find the distance $D$ between these two nodes.

You can perform the following type of operations:

Take eiter $A$ or $B$ and make it point to the father of the current node.Reset either $A$ or $B$ to point to its initial node.Check if $A$ and $B$ point to the same node.

### Interaction

You can start asking your queries right away:

Print the character F followed by either A or B for the first type of operation. After printing your query you should read the interactor's answer: $1$ if the node had a father, or $0$ if the node was the root (in this case the pointer doesn't change).Print the character R followed by either A or B for the second type of operation. You shouldn't read anything after printing this query.Print the character E for the third type of operation. After printing your query you should read the interactor's answer: $1$ if $A$ and $B$ point to the same node, $0$ otherwise.

After finding the answer, print the character A followed by the number $D$.

### Constraints and notes

This task is NOT adaptiveYou will pass the tests if the number of operations you perform is $\leq 20 * D$

InteractionF A1E1A 1F A1E0F B1E0F A1E1A 3
