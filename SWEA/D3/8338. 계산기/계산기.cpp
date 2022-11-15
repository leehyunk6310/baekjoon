#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		long dp[9];
		int num[9];
		
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> num[i];
		}

		dp[0] = num[0];

		for (int i = 1; i < N; i++)
		{
			dp[i] = max(dp[i - 1] + num[i], dp[i - 1] * num[i]);
		}
		
		cout << "#" << test_case << " " << dp[N - 1] << '\n';
	}

	return 0;
}