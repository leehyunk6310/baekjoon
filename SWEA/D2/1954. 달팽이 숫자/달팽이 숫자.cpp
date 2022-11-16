#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	int dc[4] = { 1,0,-1,0 };
	int dr[4] = { 0,1,0,-1 };
	

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int maps[11][11] = { 0, };
		int N;
		int dir = 0;
		int row = 1, col = 1;
		int cnt = 1;

		cin >> N;
		maps[1][1] = 1;
		cnt++;

		while (true)
		{			
			if (cnt == N * N + 1)
				break;			

			int ncol =  col + dc[dir];
			int nrow =  row + dr[dir];			

			if (maps[nrow][ncol] == 0 && nrow <= N && nrow >= 1 && ncol <= N && ncol >= 1)
			{
				maps[nrow][ncol] = cnt;
				row = nrow;
				col = ncol;
				cnt++;
			}
			else			
			{
				dir++;
				dir %= 4;
			}

		}

		cout << "#" << test_case << '\n';
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << maps[i][j] << " ";
			}
			cout << '\n';
		}

	}

	return 0;
}