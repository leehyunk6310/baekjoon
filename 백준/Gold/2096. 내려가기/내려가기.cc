#include <iostream>
using namespace std;

// 최대 점수와 최소 점수를 계산한다.
int N;
char maps[100000][3];
int dp[100000][3] = {0, };

int maxVal = -1, minVal = 1e9;

int main()
{   
    cin >> N;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<3; j++)
            cin >> maps[i][j];
    }
    
    dp[0][0] = maps[0][0] - '0';
    dp[0][1] = maps[0][1] - '0';
    dp[0][2] = maps[0][2] - '0';

    // for MaxVal
    for (int i=1; i<N; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (j == 0)
            {
                dp[i][j] = maps[i][j] - '0' + max(dp[i-1][j], dp[i-1][j+1]);
            }
            else if (j == 1)
            {                
                dp[i][j] = maps[i][j] - '0' + max(max(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]);
            }
            else
            {
                dp[i][j] = maps[i][j] - '0' + max(dp[i-1][j-1], dp[i-1][j]);        
            }
        }
    }
    for (int i=0; i<3; i++)
    {       
        maxVal = max(maxVal, dp[N-1][i]);
    }

    // for minVal
    for (int i=1; i<N; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (j == 0)
            {      
                dp[i][j] = maps[i][j] - '0' + min(dp[i-1][j], dp[i-1][j+1]);
            }
            else if (j == 1)
            {                            
                dp[i][j] = maps[i][j] - '0' + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]);
            }
            else
            {            
                dp[i][j] = maps[i][j] - '0' + min(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }

    for (int i=0; i<3; i++)
    {
        minVal = min(minVal, dp[N-1][i]);        
    }
    
    cout << maxVal << " " << minVal;
}