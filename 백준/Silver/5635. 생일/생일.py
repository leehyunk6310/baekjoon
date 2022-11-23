n = int(input())
t = []
for _ in range(n):
    person = list(input().split())
    t.append((int(person[3]), int(person[2]), int(person[1]), person[0]))

t.sort(key=lambda x : (x[0], x[1], x[2]))
print(t[-1][3])
print(t[0][3])
