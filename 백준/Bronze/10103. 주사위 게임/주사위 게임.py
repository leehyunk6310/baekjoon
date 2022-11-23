scoreA, scoreB = 100, 100

n = int(input())
for _ in range(n):
    A, B = map(int, input().split())

    if A > B:
        scoreB -= A
    elif A < B:
        scoreA -= B

print(scoreA)
print(scoreB)