T = int(input())

for t in range(T):
    dict = {'Y':0, 'K':0}
    for _ in range(9):
        Y, K = map(int, input().split())
        dict['Y'] += Y
        dict['K'] += K
    if (dict['Y'] > dict['K']):
        print('Yonsei')
    elif (dict['Y'] < dict['K']):
        print('Korea')
    else:
        print('Draw')
