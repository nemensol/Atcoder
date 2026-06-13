import heapq

N, K, M = map(int, input().split())
t = [[] for _ in range(N + 1)]
for i in range(N):
    C, V = map(int, input().split())
    heapq.heappush(t[C], -V)

top = []
tail = []
for r in t:
    if len(r) > 0:
        v = -heapq.heappop(r)
        heapq.heappush(top, -v)

    while len(r) > 0:
        v = -heapq.heappop(r)
        heapq.heappush(tail, -v)

ans = 0
for i in range(M):
    ans += -heapq.heappop(top)

while len(top) > 0:
    heapq.heappush(tail, heapq.heappop(top))

for i in range(K - M):
    ans += -heapq.heappop(tail)

print(ans)
