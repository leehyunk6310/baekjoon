#include <iostream>
using namespace std;

// DP?
// 한 번에 한 계단 혹은 두 계단 오를 수 있다.
// 연속된 세개의 계단을 밟을 수 없다.
// 한 칸을 두번 오르면 다음은 무조건 두칸을 건너야함.
int stairs[301];
int scores[301] = {0, };
int N;

int main()
{      
    cin >> N;    
    for (int i=1; i<=N; i++)
        cin >> stairs[i];

    scores[1] = stairs[1];
    scores[2] = stairs[1] + stairs[2];
    scores[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
    
    for (int i=4; i<=N; i++)
    {    
        scores[i] = max(scores[i-2] + stairs[i], scores[i-3] + stairs[i-1] + stairs[i]);
    }

    cout << scores[N];
    
}