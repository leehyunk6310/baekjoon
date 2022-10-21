#include <iostream>
using namespace std;

// 누적합
int N, M;
int arr[1025][1025];
int dp[1025][1025]; // (1,1) 부터 해당 (행,열) 까지의 합

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
            cin >> arr[i][j];
    }

    // 누적합 초기화
    dp[1][1] = arr[1][1];
    // 1행의 열 초기화
    for (int i=2; i<=N; i++)
    {
        dp[1][i] = dp[1][i-1] + arr[1][i];
    }
    // 1열의 행 초기화
    for (int i=2; i<=N; i++)
    {
        dp[i][1] = dp[i-1][1] + arr[i][1];
    }
    // 2행 2열 부터 초기화
    for (int i=2; i<=N; i++)
    {
        for (int j=2; j<=N; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
    }
    
    for (int i=0; i<M; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << '\n';
    }
}