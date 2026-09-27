import sys
from collections import deque

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    it = iter(input_data)
    N = int(next(it))
    M = int(next(it))
    K = int(next(it))

    grid = [next(it) for _ in range(N)]

    dist = [[-1] * M for _ in range(N)]
    q = deque()

    for _ in range(K):
        x = int(next(it)) - 1
        y = int(next(it)) - 1
        dist[x][y] = 0
        q.append((x, y))

    while q:
        r, c = q.popleft()
        d = dist[r][c]
        for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M:
                if grid[nr][nc] == '.' and dist[nr][nc] == -1:
                    dist[nr][nc] = d + 1
                    q.append((nr, nc))

    total = 0
    for r in range(N):
        for c in range(M):
            if grid[r][c] == '.':
                total += dist[r][c]

    print(total)

if __name__ == '__main__':
    main()
