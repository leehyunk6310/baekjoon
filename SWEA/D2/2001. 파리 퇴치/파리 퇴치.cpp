#include <iostream>
#include <algorithm>
using namespace std;

int sum;
int N, M;	// NXN 배열, MXM파리채
int maps[15][15];

void Count(int row, int col)
{
	int tmp = 0;
	for (int i = row; i < row +M; i++)
	{
		for (int j = col; j < col + M; j++)
		{
			tmp += maps[i][j];
		}
	}

	sum = max(sum, tmp);
}

int main()
{
	int test_case;
	int T;
	cin >> T;
	

	for (test_case = 1; test_case <= T; ++test_case)
	{
		sum = -1;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> maps[i][j];
			}
		}

		for (int i = 0; i <= N - M; i++)
		{
			for (int j = 0; j <= N - M; j++)
			{
				// M개씩 체크하는 함수.
				Count(i, j);
			}
		}

		cout << "#" << test_case << " " << sum << '\n';
	}

	return 0;
}