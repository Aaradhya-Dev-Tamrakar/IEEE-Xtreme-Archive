from collections import deque, defaultdict

def build_tree(n, parents):
    tree = defaultdict(list)
    for i in range(1, n + 1):
        if parents[i-1] != 0:
            tree[parents[i-1]].append(i)
            tree[i].append(parents[i-1])
    return tree

def bfs_distances(tree, start, n):
    dist = [-1] * (n + 1)
    dist[start] = 0
    q = deque([start])
    while q:
        u = q.popleft()
        for v in tree[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    return dist

def find_farthest(tree, start, n):
    dist = bfs_distances(tree, start, n)
    max_dist = -1
    farthest = start
    for i in range(1, n + 1):
        if dist[i] > max_dist:
            max_dist = dist[i]
            farthest = i
    return farthest, max_dist

def get_path(tree, start, end, n):
    parent = [-1] * (n + 1)
    visited = [False] * (n + 1)
    q = deque([start])
    visited[start] = True
    
    while q:
        u = q.popleft()
        if u == end:
            break
        for v in tree[u]:
            if not visited[v]:
                visited[v] = True
                parent[v] = u
                q.append(v)
    
    path = []
    curr = end
    while curr != -1:
        path.append(curr)
        curr = parent[curr]
    return path[::-1]

def count_equidistant(tree, profis, n):
    if len(profis) == 0:
        return n
    
    if len(profis) == 1:
        return n
    
    # Find diameter endpoints among Profi stores
    start = list(profis)[0]
    end1, _ = find_farthest(tree, start, n)
    end2, _ = find_farthest(tree, end1, n)
    
    # Get path between diameter endpoints
    path = get_path(tree, end1, end2, n)
    
    # For each node on path, check if equidistant from all Profis
    result = 0
    for node in path:
        dist_from_node = bfs_distances(tree, node, n)
        distances = set()
        valid = True
        for profi in profis:
            distances.add(dist_from_node[profi])
        
        if len(distances) == 1:
            result += 1
    
    return result

n, q = map(int, input().split())
parents = list(map(int, input().split()))

tree = build_tree(n, parents)
profis = set()

for _ in range(q):
    u = int(input())
    if u > 0:
        profis.add(u)
    else:
        profis.remove(-u)
    
    print(count_equidistant(tree, profis, n))