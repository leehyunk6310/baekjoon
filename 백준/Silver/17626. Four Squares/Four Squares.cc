#include <iostream>
#include <vector>
using namespace std;

// dp

int n;
int dp[50001];  // dp[i]는 i번째 수에서 최소 제곱수의 개수

int main()
{    
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i=4; i<=n; i++)
    {
        int minn = 1e9;
        // 가능한 제곱수를 뺀다.
        // 최소 minn을 구해서 1을 더한 값이 dp[i] 값이 된다.
        for (int j=1; j*j<=i; j++)
        {
            int tmp = i - j*j;
            minn = min(minn, dp[tmp]);
        }
        dp[i] = minn + 1;
    }

    cout << dp[n];
    
}