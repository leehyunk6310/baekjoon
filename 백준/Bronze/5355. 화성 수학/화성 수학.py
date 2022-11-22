T = int(input())

for t in range(T):
    A = list(input().split())
    val = float(A[0])
    A.pop(0)

    for c in A:
        if (c == '@'):
            val *= 3
        elif (c == '%'):
            val += 5
        else:
            val -= 7
    
    val = round(val, 3)
    print(f"{val:.2f}")