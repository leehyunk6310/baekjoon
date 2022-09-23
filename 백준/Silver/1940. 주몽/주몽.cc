#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[15001] = {0, };
int ptr1, ptr2;
int answer = 0;

int main()
{
    cin >> N >> M;

    for (int i=0; i<N; i++)
    {   
        cin >> arr[i];
    }

    for (int i=0; i<N; i++)
    {
        for (int j=i+1; j<N; j++)
        {
            if (arr[i] + arr[j] == M)
                answer++;
        }
    }

    cout << answer;
}