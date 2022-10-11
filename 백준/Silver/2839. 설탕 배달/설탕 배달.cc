#include <iostream>
using namespace std;

int N;
int answer = 0;
bool flag = true;
// 3kg, 5kg 설탕
// Greedy
// 1. N이 5의 배수이면 5로 나눈다.
// 2. N이 3의 배수이면 3을 깐다.
// 3. 둘 다 아니면 3을 깐다.
int main()
{
    cin >> N;
    
    while (N != 0)
    {
        if (N%5 == 0)
        {
            answer += N/5;
            N = 0;
        }
        else if (N%3 == 0)
        {
            answer += 1;
            N -= 3;
        }
        else
        {
            if (N >= 3)
            {
                answer += 1;
                N -= 3;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        cout << answer;
    else
        cout << -1;
    
}