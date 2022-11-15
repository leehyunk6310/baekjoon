#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int A[10001], B[10001];
		int cnt = 0;

		cin >> N;
		
		for (int i = 1; i <= N; i++)
		{
			cin >> A[i] >> B[i];
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if ((A[i] > A[j] && B[i] < B[j]) || (A[i] < A[j] && B[i] > B[j]))
					cnt++;
			}
		}

		cout << "#" << test_case << " " << cnt / 2 << '\n';
	}

	return 0;
}