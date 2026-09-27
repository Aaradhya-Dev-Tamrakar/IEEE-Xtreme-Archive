# Election Spies

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/election-spies/](https://csacademy.com/contest/archive/task/election-spies/)  

---

In a far away country the citizens will be called to vote in a referendum. There will be two options to vote for, let's call them $A$ and $B$.

Amongst the $N$ citizens of the country, there are two special people: one that tries to convince everybody to vote for $A$, and another one who tries to convince everybody to vote for $B$. Let's call these two spy A and spy B.

The anti-fraud department wants to identify the two spies. In order to do so, the department can run some polls. Each poll consists of choosing a subset of the $N$ citizens (possibly all), and asking for their voting intentions. The polls are anonymous, so the department can only find out the number of people from the subset that say they plan to vote for $A$ (it's assumed all the rest plan to vote for $B$). The results of the polls will respect the following:

If the subset contains only spy $A$, then he will manage to convince everybody to say they will vote for $A$.If the subset contains only spy $B$, then he will manage to convince everybody to say they will vote for $B$.If the subset contains both spies, each of them will say they plan to vote for their option, but they won't be able to influence the others.If the subset doesn't contain any spy, the people in the subset won't be influenced in any way.

When a regular citizen is not influenced by the spies (scenarios $3$ and $4$), we cannot predict his answer. Even more, the answer in a poll is not necessarily consistent with the answers given in the previous polls. Be careful though, just because the answer can't be predicted it doesn't mean it follows a random distribution.

Help the anti-fraud department identify the two spies.

### Interaction

First you should read a single integer $N$.

Then you can start asking your queries.  Each query should consist of the character Q followed by a number $M$ representing the size of the chosen subset. After that, $M$ distinct integers should follow, representing the indices of the people in the interrogated subset.

After each query read the answer given by the interactor, an integer representing the number of people that say their intention is to vote $A$.

When you are done, print the character A followed by two integers: the indices of spies $A$ and $B$.

### Constraints and notes

This task is adaptive$3 \leq N \leq 30\,000$ You are allowed to ask at most $60$ queries

InteractionExplanation5Q 3 1 2 33Q 3 2 3 41Q 3 3 4 50A 2 4If the citizens are not influenced by spies, they will vote $A\ \underline{A}\ B\ \underline{B}\ B$ everytime.The underlined elements are the spies.6Q 4 1 2 3 42Q 3 2 3 40Q 2 3 41A 1 2If the citizens are not influenced by spies, they will vote $\underline{A}\ \underline{B}\ B\ A\ A\ B$ everytime.The underlined elements are the spies.8Q 4 7 6 5 44Q 3 7 6 53Q 3 2 3 40Q 3 1 3 40Q 3 1 2 41Q 3 1 2 30A 7 8.ace-tm .ace_gutter {
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

/*# sourceURL=ace/css/ace-tm */Note for this example the citizens may change their mind.The 2 spies are the citizens $7$ and $8$Consider the  queries  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
For example, in the query Q 3 1 2 4 One of the citizens $1$, $2$ or $4$ changed their mind referring to the answers for other queries
