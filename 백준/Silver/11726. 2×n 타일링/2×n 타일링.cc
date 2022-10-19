#include <iostream>
using namespace std;

// 가로 2칸을 채우는 법은 1x2를 2개 넣는다.
// 가로 1칸을 채우는 버은 2x1을 하나 넣는다.
// dp?

int n;
int dp[1001];
int main()
{
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;

    for (int i=3; i<=n; i++)
        dp[i] = (dp[i-2] + dp[i-1]) % 10007;
    
    cout << dp[n];
    
}