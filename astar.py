import heapq

labirinto = []
dist = []
parent = []

def manhattan(a, b):
    return abs(b[0] - a[0]) + abs(b[1] - a[1])

def a_star(ini, fim, n, m):
    pq = []

    dist[ini[0]][ini[1]] = 0
    heapq.heappush(pq, (manhattan(ini, fim), ini))

    moves = [(1,0), (-1,0), (0,1), (0,-1)]

    while pq:
        d, cur = heapq.heappop(pq)

        if cur == fim:
            return

        if dist[cur[0]][cur[1]] == 10**18:
            continue

        for dx, dy in moves:
            nx = cur[0] + dx
            ny = cur[1] + dy

            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if labirinto[nx][ny] == 1:
                continue

            if dist[nx][ny] > dist[cur[0]][cur[1]] + 1:
                dist[nx][ny] = dist[cur[0]][cur[1]] + 1
                parent[nx][ny] = cur
                h = manhattan((nx, ny), fim)
                heapq.heappush(pq, (dist[nx][ny] + h, (nx, ny)))

def solve():
    beginx, beginy = map(int, input().split())
    n, m = map(int, input().split())

    global labirinto, dist, parent

    labirinto = [list(map(int, input().split())) for _ in range(n)]
    dist = [[10**18] * m for _ in range(n)]
    parent = [[(-1, -1) for _ in range(m)] for _ in range(n)]

    a_star((beginx, beginy), (n - 1, m - 1), n, m)

    if dist[n - 1][m - 1] == 10**18:
        print("No path")
        return

    print("D:", dist[n - 1][m - 1])

    path = []
    cur = (n - 1, m - 1)

    while cur != (-1, -1):
        path.append(cur)
        cur = parent[cur[0]][cur[1]]

    path.reverse()

    for x, y in path:
        print(f"({x},{y})", end=" ")
    print()

def main():
    t = int(input())
    while t:
        solve()
        t -= 1

main()
