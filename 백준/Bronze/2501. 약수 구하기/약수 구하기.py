import sys
input = sys.stdin.readline

N, K = map(int, input().split())
cnt = 0
l = []

for _ in range(1, N+1):
    if (N%_==0):
        cnt += 1
        l.append(_)
    
    if (cnt == K):
        break

if (cnt != K):
    print(0)
else:
    print(l[-1])