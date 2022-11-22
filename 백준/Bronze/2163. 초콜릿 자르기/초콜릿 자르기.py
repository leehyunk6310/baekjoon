# 가로로 N-1번 나눈다.
# N개를 M-1번 나눈다.
cnt = 0
N, M = list(map(int, input().split()))
cnt += N-1

for i in range(N):
    cnt += M-1

print(cnt)

