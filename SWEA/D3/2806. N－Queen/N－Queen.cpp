#include <iostream>
using namespace std;

// idx는 행을, 값은 열을 의미한다.
int cols[10];
int N;
int answer;

void queens(int row)
{
	if (row == N)
	{
		answer++;
		return;
	}
	// 매 열에 대하여
	for (int i = 0; i < N; i++)
	{
		int col = i;
		bool flag = true;

		for (int j = 0; j < row; j++)
		{
			// 같은 열이거나, 대각선에 있는 경우
			if (cols[j] == col || abs(col - cols[j]) == row-j)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cols[row] = col;
			queens(row + 1);
		}
	}
}

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		answer = 0;
		for (int i = 0; i < N; i++)
			cols[i] = 0;

		cin >> N;

		// 첫 행의 각 열에 대해 놓으면서 진행한다.
		for (int i = 0; i < N; i++)
		{
			cols[0] = i;
			queens(1);
		}

		cout << "#" << test_case << " " << answer << '\n';
	}

	return 0;
}