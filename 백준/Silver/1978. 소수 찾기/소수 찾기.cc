#include <iostream>
#include <math.h>
using namespace std;

int N;
int answer = 0;
bool isPrime(int n)
{
    if (n == 1)
        return false;

    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int num;
        cin >> num;
        if (isPrime(num))
            answer++;
    }
    cout << answer;
}