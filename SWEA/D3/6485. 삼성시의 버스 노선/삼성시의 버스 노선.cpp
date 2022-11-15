#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, P;
		int A[5001];
		int B[5001];
		int cnt[5001] = { 0, };
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			cin >> A[i] >> B[i];
		}

		cin >> P;

		for (int i = 0; i < P; i++)
		{
			int C;
			cin >> C;
			
			for (int j = 1; j <= N; j++)
			{
				if (A[j] <= C && C <= B[j])
					cnt[i]++;
			}
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i < P; i++)
		{
			cout << cnt[i] << " ";
		}
		cout << '\n';
	}

	return 0;
}