#include <iostream>
using namespace std;

int dp[1000001] = {0, }; // 각 값으로 이동할 때 몇번 이동했는지 체크
int X;
int main()
{
    
    cin >> X;
    // dp 끝에서 부터 체크
    for (int i=X; i>=1; i--)
    {
        if (i%3 == 0 && i != 0)
        { 
            dp[i/3] = (dp[i/3] == 0 ? dp[i]+1 : min(dp[i/3], dp[i]+1)); 
        }
        if (i%2 == 0 && i != 0)
        {
            dp[i/2] = (dp[i/2] == 0 ? dp[i]+1 : min(dp[i/2], dp[i]+1));
        }
        if (i-1 >= 1)
        {
            dp[i-1] = (dp[i-1] == 0 ? dp[i]+1 : min(dp[i-1], dp[i]+1));
        }
    }

    cout << dp[1];
}