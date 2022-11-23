while True:
    n = int(input())
    if (n == -1):
        break

    val = 0
    l = []
    for i in range(1, n):
        if (n % i == 0):
            val += i
            l.append(i)
    if (val != n):
        print(n, 'is NOT perfect.')
    else:        
        result = str(val) + ' = '
        for num in l:
            result += str(num) + ' + '
        result = result[:-2]
        print(result)