# Equal Sums

**Time Limit:** `2000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/equal-sums/](https://csacademy.com/contest/archive/task/equal-sums/)  

---

You are given a square matrix $A$ of size $N\times N$. You can perform the following type of operations:

Choose a cell and increment its value by $1$.

Perform the minimum number of operations such that the sum of elements on each row/column is the same.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains $N$ integers representing the initial values of the matrix $A$.

### Standard output

Print $N$ lines, each containing $N$ integers, representing the final values of the matrix.

### Constraints and notes

$1 \leq N \leq 1000$ $0 \leq A_{i, j} \leq 10^6$

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>1 2<br>4 3 | 3 4 <br>4 3 | By using $4$ operations, the problem constrains are achieved. For this testcase, the solution is unique. |
| 3<br>1 2 1<br>2 3 1<br>1 1 1 | 2 2 2<br>2 3 1<br>2 1 3 | .ace-tm .ace_gutter {<br>  background: #f0f0f0;<br>  color: #333;<br>}<br><br>.ace-tm .ace_print-margin {<br>  width: 1px;<br>  background: #e8e8e8;<br>}<br><br>.ace-tm .ace_fold {<br>    background-color: #6B72E6;<br>}<br><br>.ace-tm {<br>  background-color: #FFFFFF;<br>  color: black;<br>}<br><br>.ace-tm .ace_cursor {<br>  color: black;<br>}<br>        <br>.ace-tm .ace_invisible {<br>  color: rgb(191, 191, 191);<br>}<br><br>.ace-tm .ace_storage,<br>.ace-tm .ace_keyword {<br>  color: blue;<br>}<br><br>.ace-tm .ace_constant {<br>  color: rgb(197, 6, 11);<br>}<br><br>.ace-tm .ace_constant.ace_buildin {<br>  color: rgb(88, 72, 246);<br>}<br><br>.ace-tm .ace_constant.ace_language {<br>  color: rgb(88, 92, 246);<br>}<br><br>.ace-tm .ace_constant.ace_library {<br>  color: rgb(6, 150, 14);<br>}<br><br>.ace-tm .ace_invalid {<br>  background-color: rgba(255, 0, 0, 0.1);<br>  color: red;<br>}<br><br>.ace-tm .ace_support.ace_function {<br>  color: rgb(60, 76, 114);<br>}<br><br>.ace-tm .ace_support.ace_constant {<br>  color: rgb(6, 150, 14);<br>}<br><br>.ace-tm .ace_support.ace_type,<br>.ace-tm .ace_support.ace_class {<br>  color: rgb(109, 121, 222);<br>}<br><br>.ace-tm .ace_keyword.ace_operator {<br>  color: rgb(104, 118, 135);<br>}<br><br>.ace-tm .ace_string {<br>  color: rgb(3, 106, 7);<br>}<br><br>.ace-tm .ace_comment {<br>  color: rgb(76, 136, 107);<br>}<br><br>.ace-tm .ace_comment.ace_doc {<br>  color: rgb(0, 102, 255);<br>}<br><br>.ace-tm .ace_comment.ace_doc.ace_tag {<br>  color: rgb(128, 159, 191);<br>}<br><br>.ace-tm .ace_constant.ace_numeric {<br>  color: rgb(0, 0, 205);<br>}<br><br>.ace-tm .ace_variable {<br>  color: rgb(49, 132, 149);<br>}<br><br>.ace-tm .ace_xml-pe {<br>  color: rgb(104, 104, 91);<br>}<br><br>.ace-tm .ace_entity.ace_name.ace_function {<br>  color: #0000A2;<br>}<br><br><br>.ace-tm .ace_heading {<br>  color: rgb(12, 7, 255);<br>}<br><br>.ace-tm .ace_list {<br>  color:rgb(185, 6, 144);<br>}<br><br>.ace-tm .ace_meta.ace_tag {<br>  color:rgb(0, 22, 142);<br>}<br><br>.ace-tm .ace_string.ace_regex {<br>  color: rgb(255, 0, 0)<br>}<br><br>.ace-tm .ace_marker-layer .ace_selection {<br>  background: rgb(181, 213, 255);<br>}<br>.ace-tm.ace_multiselect .ace_selection.ace_start {<br>  box-shadow: 0 0 3px 0px white;<br>}<br>.ace-tm .ace_marker-layer .ace_step {<br>  background: rgb(252, 255, 0);<br>}<br><br>.ace-tm .ace_marker-layer .ace_stack {<br>  background: rgb(164, 229, 101);<br>}<br><br>.ace-tm .ace_marker-layer .ace_bracket {<br>  margin: -1px 0 0 -1px;<br>  border: 1px solid rgb(192, 192, 192);<br>}<br><br>.ace-tm .ace_marker-layer .ace_active-line {<br>  background: rgba(0, 0, 0, 0.07);<br>}<br><br>.ace-tm .ace_gutter-active-line {<br>    background-color : #dcdcdc;<br>}<br><br>.ace-tm .ace_marker-layer .ace_selected-word {<br>  background: rgb(250, 250, 255);<br>  border: 1px solid rgb(200, 200, 250);<br>}<br><br>.ace-tm .ace_indent-guide {<br>  background: url("data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAACCAYAAACZgbYnAAAAE0lEQVQImWP4////f4bLly//BwAmVgd1/w11/gAAAABJRU5ErkJggg==") right repeat-y;<br>}<br><br>.ace-tm .ace_indent-guide-active {<br>  background: url("data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAACCAYAAACZgbYnAAAACXBIWXMAAAsTAAALEwEAmpwYAAAAIGNIUk0AAHolAACAgwAA+f8AAIDpAAB1MAAA6mAAADqYAAAXb5JfxUYAAAAZSURBVHjaYvj///9/hivKyv8BAAAA//8DACLqBhbvk+/eAAAAAElFTkSuQmCC") right repeat-y;<br>}<br><br>/*# sourceURL=ace/css/ace-tm */The minimum number operations is $5$Another valid solution could be  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX |
