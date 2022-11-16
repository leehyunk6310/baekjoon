#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cnt;
int N;
char maps[8][8];

void CountCol(int row, int col)
{	
	string s = "";
	string revs = "";

	// 가로로 N개만선택하면 된다.
	for (int i = col; i < col+N; i++)
	{		
		s += maps[row][i];		
	}

	revs = s;
	reverse(revs.begin(), revs.end());

	if (revs == s)
		cnt++;
}

void CountRow(int row, int col)
{
	string s = "";
	string revs = "";

	// 가로로 N개만선택하면 된다.
	for (int i = row; i < row + N; i++)
	{
		s += maps[i][col];
	}

	revs = s;
	reverse(revs.begin(), revs.end());
	
	if (revs == s)
		cnt++;
}

int main()
{
	int test_case;
	int T;
	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cnt = 0;
		cin >> N;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> maps[i][j];
			}
		}
		// 가로
		for (int i = 0; i < 8 ; i++)
		{
			for (int j = 0; j <= 8 - N; j++)
			{
				CountCol(i, j);
			}
		}
		// 세로
		for (int i = 0; i <= 8 - N; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				CountRow(i, j);
			}
		}

		cout << "#" << test_case << " " << cnt << '\n';
	}

	return 0;
}