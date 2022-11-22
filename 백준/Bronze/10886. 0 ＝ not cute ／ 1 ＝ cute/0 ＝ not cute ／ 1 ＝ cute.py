N = int(input())
dict = {0:0, 1:0}
for i in range(N):
    op = int(input())

    dict[op] += 1
    
if (dict[0] > dict[1]):
    print('Junhee is not cute!')
else:
    print('Junhee is cute!')