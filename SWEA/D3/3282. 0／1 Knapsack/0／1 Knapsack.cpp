#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		int V[101] = { 0, }, C[101] = { 0, };
		int dp[101][1001] = { 0, };

		cin >> N >> K;
		for (int i = 1; i <= N; i++)
		{
			cin >> V[i] >> C[i];
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= K; j++)
			{
				// 담을 수 있는 경우
				if (j >= V[i])
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - V[i]] + C[i]);
				}
				// 못 담는 경우
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		cout << "#" << test_case << " " << dp[N][K] << '\n';
	}

	return 0;
}