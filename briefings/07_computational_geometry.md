# Archetype 07: Computational Geometry & Convex Hull

> **Grounding Metadata & NotebookLM Oracle**  
> - **Archetype ID:** `07_computational_geometry`  
> - **Target Notebook ID:** `95a79d26-2f87-42cd-8cb9-8361a1e56059` (*Personal Notebook: ⚙️ Aaradhya — Engineer's Personal Notebook*)  
> - **Total Archived Tasks:** `59`  
> - **Sub-Archetypes:** Points & Vectors, Cross Product Orientation Tests, Convex Hull (Monotone Chain, Graham Scan), Polygon Area (Shoelace Formula), Point-in-Polygon (Ray Casting), Rotating Calipers, Line Segment Intersection  
> - **Compiler Standards:** `g++ 15.2.0` (`-std=c++23 -O2 -pthread`) on Ubuntu 25.04 x64  

---

## 1. Executive Overview & Core Principles

Computational geometry solves geometric problems on Euclidean and Cartesian planes. Due to precision errors inherent in floating-point representations, robust competitive programming implementations strictly avoid floating-point operations wherever possible, relying on **exact integer arithmetic** via 2D vector cross and dot products.

Key geometric invariants include the **orientation test** (determines whether a sequence of three points makes a left turn, right turn, or is collinear) and the **convexity invariant** (every internal angle of a convex polygon is $\le 180^\circ$).

---

## 2. Key Mathematical Patterns & Algorithms

### 2.1 2D Vectors & Cross Product
For points $A(x_1, y_1), B(x_2, y_2), C(x_3, y_3)$, vectors $\vec{u} = \vec{AB}$ and $\vec{v} = \vec{AC}$:
$$\vec{u} \times \vec{v} = (x_2 - x_1)(y_3 - y_1) - (y_2 - y_1)(x_3 - x_1)$$
- **$\vec{u} \times \vec{v} > 0$:** Counter-clockwise turn (Left turn from $AB$ to $BC$).
- **$\vec{u} \times \vec{v} < 0$:** Clockwise turn (Right turn from $AB$ to $BC$).
- **$\vec{u} \times \vec{v} = 0$:** Collinear points.

### 2.2 Convex Hull (Andrew's Monotone Chain)
Sorts points by $X$, then $Y$. Builds lower and upper hulls in $O(N \log N)$ total time:
```cpp
struct Point {
    long long x, y;
};

long long cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> convex_hull(vector<Point>& pts) {
    int n = pts.size(), k = 0;
    if (n <= 2) return pts;
    vector<Point> h(2 * n);
    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(h[k - 2], h[k - 1], pts[i]) <= 0) k--;
        h[k++] = pts[i];
    }
    // Build upper hull
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && cross(h[k - 2], h[k - 1], pts[i]) <= 0) k--;
        h[k++] = pts[i];
    }
    h.resize(k - 1);
    return h;
}
```

### 2.3 Polygon Area (Shoelace Formula)
For vertices $(x_1, y_1), \dots, (x_n, y_n)$ in counter-clockwise order:
$$2 \cdot \text{Area} = \left| \sum_{i=1}^n (x_i y_{i+1} - x_{i+1} y_i) \right| \quad \text{where } (x_{n+1}, y_{n+1}) = (x_1, y_1)$$
Always computes twice the area as an exact integer!

### 2.4 Point in Polygon (Ray Casting / Winding Number)
Cast a horizontal ray from point $P$ towards $(+\infty, y_P)$. Count the number of intersections with polygon boundary segments:
- **Odd count:** Point is strictly inside.
- **Even count:** Point is outside.
- **Boundary check:** Verify if point lies on segment via collinear cross product and bounding box.

---

## 3. Sub-Archetypes Taxonomic Breakdown

```
Computational Geometry & Convex Hull
 ├── Vector Primitives & Predicates
 │    ├── Cross Product (Orientation tests, Left/Right turns)
 │    ├── Dot Product (Projections, Perpendicularity, Angles)
 │    └── Line Segment Intersection (Bounding box + Cross tests)
 ├── Polygons & Enclosures
 │    ├── Convex Hull (Monotone Chain, Graham Scan in O(N log N))
 │    ├── Shoelace Formula (Exact integer 2 * Area calculation)
 │    ├── Point in Polygon (Ray casting for arbitrary, Binary search for convex)
 │    └── Triangulation (Ear clipping, Convex polygon partition)
 └── Geometric Optimizations
      ├── Rotating Calipers (Diameter, Minimum bounding box, Max distance)
      └── Sweep-Line Geometry (Bentley-Ottmann segment intersections, Voronoi)
```

---

## 4. Canonical Problem Deep-Dives from Archive

### 4.1 Points in Polygon (`points_in_polygon`)
- **Contest:** Round #4 | **Difficulty:** HARD | **Platform Slug:** [`points_in_polygon`](../platforms/csacademy/tasks/points_in_polygon/statement.md)
- **Problem Statement:** Given a polygon with $N$ vertices, process $M$ queries: determine whether point $(X, Y)$ is inside, on the boundary, or outside.
- **Mathematical Invariant:**
  Ray casting with careful handling of vertex crossings (count only edges whose $Y$-interval contains $y_P$ with semi-open boundary $[y_1, y_2)$).
- **Optimal Complexity:** $O(N)$ per query, $O(N \cdot M)$ overall.

### 4.2 Moving Segments (`moving_segments`)
- **Contest:** Round #2 | **Difficulty:** MEDIUM | **Platform Slug:** [`moving_segments`](../platforms/csacademy/tasks/moving_segments/statement.md)
- **Problem Statement:** Given line segments with velocities, determine if and when intersections occur.
- **Mathematical Invariant:**
  Transform to relative velocity frame. Compute parameterized collision times $t \ge 0$ where endpoints become collinear.
- **Optimal Complexity:** $O(N \log N)$ sweep-line or $O(N^2)$ direct pairwise verification.

---

## 5. Optimal Complexity Tips & Competitive Pitfalls

1. **Integer Arithmetic Preservation:** Never use `atan2` or floating-point slopes (`dy / dx`) when sorting points. Instead, sort by cross product orientation relative to a reference origin:
   ```cpp
   bool compare(Point a, Point b) {
       return cross(origin, a, b) > 0;
   }
   ```
2. **Cross Product Overflows:** Cross products involve terms like $x_i \cdot y_j$. If coordinates reach $10^9$, product reaches $10^{18}$, requiring `long long` or `__int128_t` to avoid silent 32-bit overflow.
3. **Collinear Edge Degeneracy:** Clarify whether the convex hull must include strictly collinear boundary vertices. Adjust `< 0` vs `<= 0` in cross product checks accordingly.

---

## 6. Comprehensive Archive Task Registry (59 Tasks)

| Slug | Title | Difficulty | Contest | Solved Ratio | Archive Link |
| :--- | :--- | :---: | :--- | :---: | :---: |
| `bounding-box` | **Bounding Box** | `EASY` | Round #33 (Div. 2 only) | 98% | [`bounding-box`](../platforms/csacademy/tasks/bounding-box/statement.md) |
| `check-square` | **Check Square** | `EASY` | Round #50 (Div. 2 only) | 95% | [`check-square`](../platforms/csacademy/tasks/check-square/statement.md) |
| `circle-elimination` | **Circle Elimination** | `EASY` | Round #39 (Div. 2 only) | 94% | [`circle-elimination`](../platforms/csacademy/tasks/circle-elimination/statement.md) |
| `dominant-point` | **Dominant Point** | `EASY` | Round #13 | 97% | [`dominant-point`](../platforms/csacademy/tasks/dominant-point/statement.md) |
| `falling-leaves` | **Falling Leaves** | `EASY` | Round #56 | 89% | [`falling-leaves`](../platforms/csacademy/tasks/falling-leaves/statement.md) |
| `fast-travel` | **Fast Travel** | `EASY` | Round #23 (Div. 2 only) | 80% | [`fast-travel`](../platforms/csacademy/tasks/fast-travel/statement.md) |
| `independent-rectangles` | **Independent Rectangles** | `EASY` | Round #12 (Div. 2 only) | 77% | [`independent-rectangles`](../platforms/csacademy/tasks/independent-rectangles/statement.md) |
| `matrix_rotations` | **Matrix Rotations** | `EASY` | Beta Round #5 | 91% | [`matrix_rotations`](../platforms/csacademy/tasks/matrix_rotations/statement.md) |
| `squarish-rectangle` | **Squarish Rectangle** | `EASY` | Round #18 | 95% | [`squarish-rectangle`](../platforms/csacademy/tasks/squarish-rectangle/statement.md) |
| `surrounded-rectangle` | **Surrounded Rectangle** | `EASY` | Round #14 (Div. 2 only) | 76% | [`surrounded-rectangle`](../platforms/csacademy/tasks/surrounded-rectangle/statement.md) |
| `travel-distance` | **Travel Distance** | `EASY` | Round #50 (Div. 2 only) | 98% | [`travel-distance`](../platforms/csacademy/tasks/travel-distance/statement.md) |
| `triangle-count` | **Triangle Count** | `EASY` | Round #22 (Div. 2 only) | 99% | [`triangle-count`](../platforms/csacademy/tasks/triangle-count/statement.md) |
| `bbox-count` | **BBox Count** | `HARD` | Round #36 (Div. 2 only) | 90% | [`bbox-count`](../platforms/csacademy/tasks/bbox-count/statement.md) |
| `cyclic-shifts` | **Cyclic Shifts** | `HARD` | Round #67 | 64% | [`cyclic-shifts`](../platforms/csacademy/tasks/cyclic-shifts/statement.md) |
| `empty-triangles` | **Empty Triangles** | `HARD` | IOI 2016 Training Round #5 | 54% | [`empty-triangles`](../platforms/csacademy/tasks/empty-triangles/statement.md) |
| `gcd-on-a-circle` | **Gcd on a Circle** | `HARD` | Round #18 | 83% | [`gcd-on-a-circle`](../platforms/csacademy/tasks/gcd-on-a-circle/statement.md) |
| `lamp` | **Lamp** | `HARD` | Romanian IOI 2017 Selection #4 | 61% | [`lamp`](../platforms/csacademy/tasks/lamp/statement.md) |
| `manhattan` | **Manhattan** | `HARD` | Romanian IOI 2017 Selection #1 | 50% | [`manhattan`](../platforms/csacademy/tasks/manhattan/statement.md) |
| `nonempty-rectangles` | **Nonempty Rectangles** | `HARD` | IOI 2016 Training Round #4 | 68% | [`nonempty-rectangles`](../platforms/csacademy/tasks/nonempty-rectangles/statement.md) |
| `pirouettes` | **Pirouettes** | `HARD` | Romanian IOI 2017 Selection #2 | 62% | [`pirouettes`](../platforms/csacademy/tasks/pirouettes/statement.md) |
| `points-matching` | **Points Matching** | `HARD` | Round #15 | 73% | [`points-matching`](../platforms/csacademy/tasks/points-matching/statement.md) |
| `points_in_polygon` | **Points in Polygon** | `HARD` | IOI 2016 Training Round #2 | 41% | [`points_in_polygon`](../platforms/csacademy/tasks/points_in_polygon/statement.md) |
| `polygon_partition` | **Polygon Partition** | `HARD` | IOI 2016 Training Round #1 | 81% | [`polygon_partition`](../platforms/csacademy/tasks/polygon_partition/statement.md) |
| `rooms` | **Rooms** | `HARD` | Romanian IOI 2017 Selection #1 | 77% | [`rooms`](../platforms/csacademy/tasks/rooms/statement.md) |
| `sum-of-squares` | **Sum of Squares** | `HARD` | (Out of Beta) Round #9 | 76% | [`sum-of-squares`](../platforms/csacademy/tasks/sum-of-squares/statement.md) |
| `tournament` | **Tournament** | `HARD` | Round #80 (unrated, based on Romanian Olympiad IOI selection camp) | 79% | [`tournament`](../platforms/csacademy/tasks/tournament/statement.md) |
| `aggressive-pawns` | **Aggressive Pawns** | `MEDIUM` | CS Academy Archive | 93% | [`aggressive-pawns`](../platforms/csacademy/tasks/aggressive-pawns/statement.md) |
| `back-in-business` | **Back in Business** | `MEDIUM` | CS Academy Archive | 88% | [`back-in-business`](../platforms/csacademy/tasks/back-in-business/statement.md) |
| `circle-kingdom` | **Circle Kingdom** | `MEDIUM` | Round #72 | 87% | [`circle-kingdom`](../platforms/csacademy/tasks/circle-kingdom/statement.md) |
| `city-attractions` | **City Attractions** | `MEDIUM` | Balkan OI 2017 Day 2 | 69% | [`city-attractions`](../platforms/csacademy/tasks/city-attractions/statement.md) |
| `city-break` | **City Break** | `MEDIUM` | CS Academy Archive | 95% | [`city-break`](../platforms/csacademy/tasks/city-break/statement.md) |
| `count-squares` | **Count Squares** | `MEDIUM` | Round #44 (Div. 2 only) | 94% | [`count-squares`](../platforms/csacademy/tasks/count-squares/statement.md) |
| `disk-mechanism` | **Disk Mechanism** | `MEDIUM` | Round #23 (Div. 2 only) | 92% | [`disk-mechanism`](../platforms/csacademy/tasks/disk-mechanism/statement.md) |
| `dominant-free-sets` | **Dominant Free Sets** | `MEDIUM` | Round #48 (Div. 2 only) | 88% | [`dominant-free-sets`](../platforms/csacademy/tasks/dominant-free-sets/statement.md) |
| `equidistant-points` | **Equidistant Points** | `MEDIUM` | Round #32 | 89% | [`equidistant-points`](../platforms/csacademy/tasks/equidistant-points/statement.md) |
| `falling-balls` | **Falling Balls** | `MEDIUM` | Round #67 | 81% | [`falling-balls`](../platforms/csacademy/tasks/falling-balls/statement.md) |
| `fold-polygon` | **Fold Polygon** | `MEDIUM` | CS Academy Archive | 60% | [`fold-polygon`](../platforms/csacademy/tasks/fold-polygon/statement.md) |
| `force_graph` | **Force Graph** | `MEDIUM` | Beta Round #5 | 85% | [`force_graph`](../platforms/csacademy/tasks/force_graph/statement.md) |
| `ginas-necklace` | **Gina's Necklace** | `MEDIUM` | CS Academy Archive | 66% | [`ginas-necklace`](../platforms/csacademy/tasks/ginas-necklace/statement.md) |
| `hallway` | **Hallway** | `MEDIUM` | IOI 2016 Training Round #1 | 71% | [`hallway`](../platforms/csacademy/tasks/hallway/statement.md) |
| `heroes` | **Heroes** | `MEDIUM` | RMI 2023 - Day 1 Mirror | 21% | [`heroes`](../platforms/csacademy/tasks/heroes/statement.md) |
| `jetpack` | **Jetpack** | `MEDIUM` | (Out of Beta) Round #9 | 68% | [`jetpack`](../platforms/csacademy/tasks/jetpack/statement.md) |
| `lonely-points` | **Lonely Points** | `MEDIUM` | CS Academy Archive | 83% | [`lonely-points`](../platforms/csacademy/tasks/lonely-points/statement.md) |
| `manhattan-center` | **Manhattan Center** | `MEDIUM` | CS Academy Archive | 76% | [`manhattan-center`](../platforms/csacademy/tasks/manhattan-center/statement.md) |
| `manhattan-distances` | **Manhattan Distances** | `MEDIUM` | Round #51 (Div. 2 only) | 84% | [`manhattan-distances`](../platforms/csacademy/tasks/manhattan-distances/statement.md) |
| `moving_segments` | **Moving Segments** | `MEDIUM` | Beta Round #3 | 81% | [`moving_segments`](../platforms/csacademy/tasks/moving_segments/statement.md) |
| `oil-wells` | **Oil Wells** | `MEDIUM` | Romanian IOI Selection 2023 - Day 2 | 40% | [`oil-wells`](../platforms/csacademy/tasks/oil-wells/statement.md) |
| `parallel-rectangles` | **Parallel Rectangles** | `MEDIUM` | Round #53 (Div. 2 only) | 66% | [`parallel-rectangles`](../platforms/csacademy/tasks/parallel-rectangles/statement.md) |
| `platforms` | **Platforms** | `MEDIUM` | Beta Round #1 | 60% | [`platforms`](../platforms/csacademy/tasks/platforms/statement.md) |
| `point-in-kgon` | **Point in Kgon** | `MEDIUM` | Round #34 (Div. 2 only) | 91% | [`point-in-kgon`](../platforms/csacademy/tasks/point-in-kgon/statement.md) |
| `rectangle-fit` | **Rectangle Fit** | `MEDIUM` | CS Academy Archive | 88% | [`rectangle-fit`](../platforms/csacademy/tasks/rectangle-fit/statement.md) |
| `right-triangles` | **Right Triangles** | `MEDIUM` | Round #68 (Div. 2 only) | 79% | [`right-triangles`](../platforms/csacademy/tasks/right-triangles/statement.md) |
| `sniper` | **Sniper** | `MEDIUM` | Romanian IOI Selection 2023 - Day 3 | 50% | [`sniper`](../platforms/csacademy/tasks/sniper/statement.md) |
| `squared-ends` | **Squared Ends** | `MEDIUM` | Round #70 | 81% | [`squared-ends`](../platforms/csacademy/tasks/squared-ends/statement.md) |
| `strange-distance` | **Strange Distance** | `MEDIUM` | Beta Round #8 | 74% | [`strange-distance`](../platforms/csacademy/tasks/strange-distance/statement.md) |
| `subinterval-division` | **Subinterval Division** | `MEDIUM` | Round #33 (Div. 2 only) | 61% | [`subinterval-division`](../platforms/csacademy/tasks/subinterval-division/statement.md) |
| `Sugarel-s-Garden` | **Sugarel’s Garden** | `MEDIUM` | CS Academy Archive | 77% | [`Sugarel-s-Garden`](../platforms/csacademy/tasks/Sugarel-s-Garden/statement.md) |
| `tale` | **Tale** | `MEDIUM` | Balkan OI 2017 Day 1 | 20% | [`tale`](../platforms/csacademy/tasks/tale/statement.md) |
| `the-sprawl` | **The Sprawl** | `MEDIUM` | CS Academy Archive | 76% | [`the-sprawl`](../platforms/csacademy/tasks/the-sprawl/statement.md) |
