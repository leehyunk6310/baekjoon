T = int(input())

for i in range (T):
    N = int(input())
    l = []

    for _ in range(N):
        info = list(input().split())
        school = info[0]
        drinks = int(info[1])
        l.append((drinks, school))
    
    l.sort(reverse=True)
    print(l[0][1])
    
    