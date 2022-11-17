#include <iostream>
#include <string>
#include <set>
using namespace std;

int arr[4][4];
set<string> answer;
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

void dfs(int row, int col, int cnt, string s)
{
	if (cnt == 7)
	{
		answer.insert(s);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nr = row + dr[i];
		int nc = col + dc[i];

		if (nr >= 0 && nc >= 0 && nr < 4 && nc < 4)
		{
			dfs(nr, nc, cnt + 1, s + to_string(arr[nr][nc]));
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
		answer.clear();

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> arr[i][j];
			}
		}


		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				dfs(i, j, 1, to_string(arr[i][j]));
			}
		}

		cout << "#" << test_case << " " << answer.size() << '\n';
	}

	

	return 0;
}