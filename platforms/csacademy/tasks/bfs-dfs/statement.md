# BFS-DFS

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bfs-dfs/](https://csacademy.com/contest/archive/task/bfs-dfs/)  

---

.ace-tm .ace_gutter {
  background: #f0f0f0;
  color: #333;
}

.ace-tm .ace_print-margin {
  width: 1px;
  background: #e8e8e8;
}

.ace-tm .ace_fold {
    background-color: #6B72E6;
}

.ace-tm {
  background-color: #FFFFFF;
  color: black;
}

.ace-tm .ace_cursor {
  color: black;
}
        
.ace-tm .ace_invisible {
  color: rgb(191, 191, 191);
}

.ace-tm .ace_storage,
.ace-tm .ace_keyword {
  color: blue;
}

.ace-tm .ace_constant {
  color: rgb(197, 6, 11);
}

.ace-tm .ace_constant.ace_buildin {
  color: rgb(88, 72, 246);
}

.ace-tm .ace_constant.ace_language {
  color: rgb(88, 92, 246);
}

.ace-tm .ace_constant.ace_library {
  color: rgb(6, 150, 14);
}

.ace-tm .ace_invalid {
  background-color: rgba(255, 0, 0, 0.1);
  color: red;
}

.ace-tm .ace_support.ace_function {
  color: rgb(60, 76, 114);
}

.ace-tm .ace_support.ace_constant {
  color: rgb(6, 150, 14);
}

.ace-tm .ace_support.ace_type,
.ace-tm .ace_support.ace_class {
  color: rgb(109, 121, 222);
}

.ace-tm .ace_keyword.ace_operator {
  color: rgb(104, 118, 135);
}

.ace-tm .ace_string {
  color: rgb(3, 106, 7);
}

.ace-tm .ace_comment {
  color: rgb(76, 136, 107);
}

.ace-tm .ace_comment.ace_doc {
  color: rgb(0, 102, 255);
}

.ace-tm .ace_comment.ace_doc.ace_tag {
  color: rgb(128, 159, 191);
}

.ace-tm .ace_constant.ace_numeric {
  color: rgb(0, 0, 205);
}

.ace-tm .ace_variable {
  color: rgb(49, 132, 149);
}

.ace-tm .ace_xml-pe {
  color: rgb(104, 104, 91);
}

.ace-tm .ace_entity.ace_name.ace_function {
  color: #0000A2;
}

.ace-tm .ace_heading {
  color: rgb(12, 7, 255);
}

.ace-tm .ace_list {
  color:rgb(185, 6, 144);
}

.ace-tm .ace_meta.ace_tag {
  color:rgb(0, 22, 142);
}

.ace-tm .ace_string.ace_regex {
  color: rgb(255, 0, 0)
}

.ace-tm .ace_marker-layer .ace_selection {
  background: rgb(181, 213, 255);
}
.ace-tm.ace_multiselect .ace_selection.ace_start {
  box-shadow: 0 0 3px 0px white;
}
.ace-tm .ace_marker-layer .ace_step {
  background: rgb(252, 255, 0);
}

.ace-tm .ace_marker-layer .ace_stack {
  background: rgb(164, 229, 101);
}

.ace-tm .ace_marker-layer .ace_bracket {
  margin: -1px 0 0 -1px;
  border: 1px solid rgb(192, 192, 192);
}

.ace-tm .ace_marker-layer .ace_active-line {
  background: rgba(0, 0, 0, 0.07);
}

.ace-tm .ace_gutter-active-line {
    background-color : #dcdcdc;
}

.ace-tm .ace_marker-layer .ace_selected-word {
  background: rgb(250, 250, 255);
  border: 1px solid rgb(200, 200, 250);
}

.ace-tm .ace_indent-guide {
  background: url("data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAACCAYAAACZgbYnAAAAE0lEQVQImWP4////f4bLly//BwAmVgd1/w11/gAAAABJRU5ErkJggg==") right repeat-y;
}

.ace-tm .ace_indent-guide-active {
  background: url("data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAACCAYAAACZgbYnAAAACXBIWXMAAAsTAAALEwEAmpwYAAAAIGNIUk0AAHolAACAgwAA+f8AAIDpAAB1MAAA6mAAADqYAAAXb5JfxUYAAAAZSURBVHjaYvj///9/hivKyv8BAAAA//8DACLqBhbvk+/eAAAAAElFTkSuQmCC") right repeat-y;
}

/*# sourceURL=ace/css/ace-tm */

In this problem you are given the two orders of visiting the nodes in a BFS and a DFS, starting in node $1$. Generate the edge list of a simple, undirected, connected graph corresponding to these orders.

### Statement clarification

One of the standard ways of storing a graph is using adjacency lists. Usually, the input is given as a list of edges. The program reads the numbers of nodes and edges, creates an empty list for each node, and then proceeds to read the edges. When an edge $(a, b)$ is read, $a$ is appended to the list of $b$ and $b$ is appended to the list of $a$. Consider the following input:

  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

We have a graph with $6$ nodes and $8$ edges:

123456

And we create the following lists:

Node $1$: $[3, 5, 6]$ Node $2$: $[5, 6]$ Node $3$: $[1, 4, 5]$ Node $4$: $[3]$ Node $5$: $[1, 2, 3, 6]$ Node $6$: $[1, 2, 5]$ 

In this problem we are concerned with the two most popular algorithms for traversing a graph: the Breadth First Search (BFS) and the Depth First Search (DFS).

The BFS pushes the starting node in a queue. While the queue is not empty, we pop the first node from the queue, go through its adjacency list, and enqueue the unvisited neighbours.

The DFS is usually implemented as a recursive function. First we call the function for the starting node. For each call, we go through the adjacency list of the current node, and recursively call the function for the unvisited neighbours.

Notice that the order of visiting the nodes is uniquely determined for both algorithms.

### Standard input

The first line contains a single integer $N$, representing the number of nodes.

The second line contains a permutation of size $N$, representing the order of visiting the nodes for the BFS.

The third line contains a permutation of size $N$, representing the order of visiting the nodes for the DFS.

### Standard output

If there is no solution, output $-1$.

Otherwise, print a single integer $M$, representing the number of edges, on the first line.

Each of the next $M$ lines should contain two integers $a$ and $b$ representing two nodes that share an edge.

### Constraints and notes

$1 \leq N \leq 4096$ The number of edges $M$ should be at most $10^5$ The two permutations will always start with $1$ The graph is considered to be undirected. Multiple edges and self loops are not allowed, and the graph should be connected.

| Input | Output | Explanation |
| --- | --- | --- |
| 6<br>1 3 5 6 4 2<br>1 3 4 5 2 6 | 8<br>1 3<br>1 5<br>1 6<br>2 5<br>2 6<br>3 4<br>3 5<br>5 6 | The labels on the edges represent the indices in the output edges.12345678123456 |
| 4<br>1 2 4 3<br>1 2 3 4 | 4<br>1 2<br>1 4<br>3 4<br>2 3 | 12341234 |
| 6<br>1 2 6 3 4 5<br>1 2 6 3 4 5 | 7<br>1 2<br>2 6<br>2 3<br>2 4<br>4 5<br>1 6<br>3 4 | 1234567123456 |
| 8<br>1 3 5 4 7 8 2 6<br>1 3 7 2 8 6 5 4 | 10<br>2 8<br>1 3<br>1 5<br>3 7<br>2 7<br>1 4<br>4 2<br>2 6<br>8 6<br>5 8 | 1234567891012345678 |
