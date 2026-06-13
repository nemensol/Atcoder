N, K, M = map(int, input().split())
t = [[] for _ in range(N + 1)]
for i in range(N):
    C, V = map(int, input().split())
    t[C].append(V)

top = []
tail = []
for r in t:
    if len(r) > 0:
        r.sort(reverse=True)
        top.append(r[0])
        tail += r[1:]

top.sort(reverse=True)
tail += top[M:]
tail.sort(reverse=True)
print(sum(top[:M]) + sum(tail[: K - M]))
