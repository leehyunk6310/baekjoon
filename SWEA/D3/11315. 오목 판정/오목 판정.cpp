#include <iostream>
using namespace std;

char arr[20][20];
int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };
int N;
// 2차원 배열을 돌면서 상하좌우대각선 방향으로 뻗어나가면서 체크한다.
// 한 방향에 대해서 한칸, 두칸 ... 5칸 이런 식으로 뻗어나감 조건이 만족한다면
// 조건은 해당 위치에 O이고, 2차원 배열의 범위 안에 속해야함

bool dfs(int row, int col)
{	
	for (int i = 0; i < 8; i++)
	{		
		for (int j = 1; j <= 4; j++)
		{
			int nrow = row + dr[i] * j;
			int ncol = col + dc[i] * j;
			// 범위를 벗어나면 break;
			if (nrow >= N || ncol >= N || nrow < 0 || ncol < 0 || arr[nrow][ncol] == '.')
				break;
			if (j == 4)
				return true;
		}
	}

	return false;
}

int main()
{
	int test_case;
	int T;
	cin >> T;

	
	for (test_case = 1; test_case <= T; ++test_case)
	{	
		bool flag = false;
		cin >> N;

		// 그래프 초기화
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];
		}

		for (int i = 0; i < N; i++)
		{
			if (flag)
				break;

			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 'o')
					if (dfs(i, j))
					{
						flag = true;
						break;
					}
			}
		}
		
        cout << "#" << test_case << " ";
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}