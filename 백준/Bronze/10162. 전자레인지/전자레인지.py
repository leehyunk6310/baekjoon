A, B, C = 0, 0, 0

T = int(input())

while (T >= 300):
    A += 1
    T -= 300
while (T >= 60):
    B += 1
    T -= 60
while (T >= 10):
    C += 1
    T -= 10

if (T == 0):
    print(A, B, C)
else:
    print(-1)