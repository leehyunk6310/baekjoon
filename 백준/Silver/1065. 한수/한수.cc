#include <iostream>
using namespace std;

int N;
int answer = 0;
int main()
{
    cin >> N;
    if (N <= 99)
        answer = N;
    else
    {
        answer = 99;
        for (int i=100; i<=N; i++)
        {
            int hundred = i/100;
            int ten = (i/10) % 10;
            int one = i % 10;

            if (hundred - ten == ten - one)
                answer++;                    
        }
    }

    cout << answer;
    
}