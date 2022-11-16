#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	int A[20];
	int B[20];

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		int maxVal = -1;
		cin >> N >> M;

		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < M; i++)
			cin >> B[i];

		// 길이가 짧은 녀석이 움직이면서 계산해야한다.
		if (N > M)
		{
			int indexA = 0;
			while (indexA != N - M)
			{
				int sum = 0;
				for (int i = 0; i < M; i++)
				{
					sum += B[i] * A[indexA + i];
				}
				indexA++;
				maxVal = max(maxVal, sum);
			}			
		}
		else if (N < M)
		{
			int indexB = 0;
			while (indexB != M - N + 1)
			{
				int sum = 0;
				for (int i = 0; i < N; i++)
				{
					sum += B[indexB + i] * A[i];
				}				
				indexB++;
				maxVal = max(maxVal, sum);
			}
		}
		else
		{
			int sum = 0;
			for (int i = 0; i < N; i++)
			{
				sum += B[i] * A[i];
			}
			maxVal = max(maxVal, sum);
		}

		cout << "#" << test_case << " " << maxVal << '\n';
	}

	return 0;
}