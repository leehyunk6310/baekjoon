#include <iostream>
using namespace std;

int N;
int dp[1001];   // 해당 돌의 개수에 대하여 현재 플레이한 횟수
                // 홀수면 SK. 짝수면 CY를 출력
// 상근이가 먼저 시작
// 돌은 1개 또는 3개를 가져간다
// 이기는 법은 자기 차례일때 돌이 3개 또는 2개가 남아야함.
int main()
{
    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i=3; i<=N; i++)
    {
        dp[i] = min(dp[i-1] + 1, dp[i-3] + 1);
    }

    cout << (dp[N] % 2 == 1 ? "SK" : "CY");

}