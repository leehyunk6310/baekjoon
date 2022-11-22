bowls = list(input())
answer = 10

for i in range(1, len(bowls)):
    if (bowls[i-1] != bowls[i]):
        answer += 10
    else:
        answer += 5

print(answer)