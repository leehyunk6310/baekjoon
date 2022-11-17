#include <iostream>
using namespace std;

int arr[15][15];
int cnt;
bool visited[15][15] = { false, };
int N, K;

// 오른쪽으로 방문함
int dfsCol(int row, int col, int c)
{	
	while (col + 1 < N && arr[row][col+1] == 1)
	{
		visited[row][col + 1] = true;
		c++;
		col++;
	}
	return c;
}

// 아래로 방문함
int dfsRow(int row, int col, int c)
{
	while (row + 1 < N && arr[row+1][col] == 1)
	{
		visited[row+1][col] = true;
		c++;
		row++;
	}
	return c;
}

int main()
{
	int test_case;
	int T;
	cin >> T;
	// 2차원 배열을 순회하면서 1을 만난경우 우선 좌우로
	// 다음은 상하로 뻗어나가면서 길이를 파악한다.
	// bfs도 가능할까?

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				visited[i][j] = false;
			}
		}
		cnt = 0;

		cin >> N >> K;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 1 && !visited[i][j])
				{
					visited[i][j] = true;
					int c =dfsCol(i, j,1);
					if (c == K)
						cnt++;
				}
			}
		}

		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				visited[i][j] = false;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 1 && !visited[i][j])
				{
					visited[i][j] = true;
					int c = dfsRow(i, j, 1);
					if (c == K)
						cnt++;
				}
			}
		}

		cout << "#" << test_case << " "<< cnt << '\n';
		
	}

	return 0;
}