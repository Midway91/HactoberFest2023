from heapq import heappush, heappop
import heapq
for _ in range(int(input())):
    N,M = map(int, input().split())
    g = [[] for _ in range(N)]
    for _ in range(M):
        x,y,r = map(int,input().split())
        x,y = x-1,y-1
        g[x].append((r,y))
        g[y].append((r,x))
    S = int(input()) - 1
    paths = [-1]*N
    visited = [False]*N
    visited[S] = True
    cd = 0
    q = [(cd,S)]
    while q:
        d,c = heappop(q)
        for r,n in g[c]:
            nd = d+r
            if not visited[n]:
                visited[n] = True
                heappush(q, (nd,n))
                paths[n] = nd
            else:
                if paths[n] > nd:
                    index = q.index((paths[n],n))
                    q[index] = (nd,n)
                    heapq._siftdown(q, 0, index)
                    paths[n] = nd
                
                
                
    paths = paths[:S] + paths[S+1:]
    print(" ".join(map(str, paths)))
