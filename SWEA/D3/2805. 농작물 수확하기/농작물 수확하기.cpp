#include <iostream>
using namespace std;

int arr[49][49];

int main()
{
	int test_case;
	int T;
	cin >> T;
	// 전체에서 빼는게 나아 보인다.
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, sum = 0, tSum = 0;
		cin >> N;

		// 배열 초기화
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				char c;
				cin >> c;
				arr[i][j] = c - '0';
				tSum += arr[i][j];
			}
		}

		// 좌상
		for (int i = 0; i < N / 2; i++)
		{
			for (int j = 0; j < N / 2 - i; j++)
			{
				// cout << arr[i][j] << " ";
				sum += arr[i][j];
			}
		}
		// 좌하
		for (int i = N - N / 2; i < N; i++)
		{
			for (int j = 0; j < i - N / 2; j++)
			{
				// cout << arr[i][j] << " ";
				sum += arr[i][j];
			}
		}
		// 우상
		for (int i = 0; i < N / 2; i++)
		{
			for (int j = N - 1; j > N / 2 + i; j--)
			{
				// cout << arr[i][j] << " ";
				sum += arr[i][j];
			}
		}

		// 우하
		for (int i = N - N / 2; i < N; i++)
		{
			for (int j = N + N / 2 - i; j < N; j++)
			{
				// cout << arr[i][j] << " ";
				sum += arr[i][j];
			}
		}

		cout << "#" << test_case << " " <<  tSum - sum << '\n';
		
	}

	return 0;
}