# Soccer Field

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/soccer-field/](https://csacademy.com/contest/archive/task/soccer-field/)  

---

Alice wants to plant grass into her garden. She has spoke with two gardening companies, which offered to plant grass for her. The first company will plant grass in a rectangle of dimensions $L_1\times H_1$, while the second one will plant grass in a rectangle of dimensions $L_2\times H_2$.  Due to technical limitations, the sides of the rectangles must be parallel with the North-South and East-West directions.

  

After the grass is planted, she wants to create a soccer filed, in form of a rectangular piece of land, which is fully covered with grass. She wants the soccer field to be as large as possible. The sides of the soccer field rectangle must also be parallel with the North-South and East-West directions.

  

You must print the maximum area she can obtain by choosing conveniently the way in which the two gardening companies plant the grass. The rectangles can be placed in any way, and even rotated if needed.

  

In the picture below, you can see possible placements of the soccer field with green, and incorrect one with red. Note that in all 4 samples, both rectangles $L_1, \times H_1$ and $L_2 \times H_2$ are placed correctly (the sides are parallel with the North-South and East-West directions.)

Theese samples are showing some correct placement of the soccer filed, not the optimal one, and they do not correcpond to any of the examples test cases.

  

### Standard input

The only line of the input has the numers $L_1,  H_1$ and $L_2, H_2$.

### Standard output

You should output a single integer, the area of the maximum soccer field.

### Constraints and notes

  
$1 \leq L_1, H_1, L_2, H_2\leq 100$

| Input | Output |
| --- | --- |
| 3 2 1 4 | 9 |
| 2 2 2 3 | 10 |
