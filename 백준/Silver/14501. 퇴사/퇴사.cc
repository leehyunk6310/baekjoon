#include <iostream>
using namespace std;

int N;
int T[16];
int P[16];
int dp[16] = {0, };
int main()
{
    cin >> N;
    for (int i=1; i<=N; i++)
    {
        cin >> T[i] >> P[i];
    }
    
    int deadline;
    for (int i=N; i>0; i--)
    {
        deadline = i + T[i];
        // 상담 불가
        if (deadline > N+1)
            dp[i] = dp[i+1];
        else
            dp[i] = max(dp[i+1], dp[deadline] + P[i]);

    }

    cout << dp[1];
}