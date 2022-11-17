#include <iostream>
#include <queue>
using namespace std;

int arr[16][16];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int main()
{
	int test_case;
	int T = 10;
	
	// BFS로 접근
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int t;
		queue<pair<int, int>> q;		
		pair<int, int> dest;
		bool visited[16][16] = { false, };
		bool flag = false;

		cin >> t;
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				char c;
				cin >> c;
				arr[i][j] = c - '0';
				if (arr[i][j] == 2)
				{
					q.push({ i,j });
					visited[i][j] = true;
				}
				if (arr[i][j] == 3)
					dest = { i, j };
			}
		}
		
		while (!q.empty())
		{
			int row = q.front().first;
			int col = q.front().second;

			if (row == dest.first && col == dest.second)
			{
				flag = true;
				break;
			}
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nrow = row + dr[i];
				int ncol = col + dc[i];

				if (nrow < 0 || ncol < 0 || nrow >= 16 || ncol >= 16)
					continue;
				if (arr[nrow][ncol] == 1)
					continue;
				if (visited[nrow][ncol])
					continue;

				visited[nrow][ncol] = true;
				q.push({ nrow, ncol });
			}
		}

		cout << "#" << t << " ";
		if (flag)
			cout << 1;
		else
			cout << 0;
		cout << '\n';

	}

	return 0;
}