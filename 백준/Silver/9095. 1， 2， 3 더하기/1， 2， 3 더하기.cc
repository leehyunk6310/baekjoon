#include <iostream>
#include <vector>
using namespace std;

// dp
int t;
int dp[12];
vector<int> answer;

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    cin >> t;
    for (int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        for (int j=4; j<=n; j++)
        {
            dp[j] = dp[j-3] + dp[j-2] + dp[j-1];
        }
        answer.push_back(dp[n]);
    }

    for (auto num : answer)
        cout << num << '\n';


    
}