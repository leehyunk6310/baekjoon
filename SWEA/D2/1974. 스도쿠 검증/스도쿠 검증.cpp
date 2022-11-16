#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int board[9][9];
		bool flag = true;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> board[i][j];				
			}			
		}		
		// 가로줄에 대하여 체크
		for (int i = 0; i < 9; i++)
		{
			unordered_map<int, int> row;

			for (int j = 0; j < 9; j++)
			{
				row[board[i][j]]++;
			}

			if (row.size() != 9)
			{
				flag = false;
				break;
			}
		}

		// 세로줄에 대하여 체크
		if (flag)
		{
			for (int i = 0; i < 9; i++)
			{
				unordered_map<int, int> col;

				for (int j = 0; j < 9; j++)
				{
					col[board[j][i]]++;
				}

				if (col.size() != 9)
				{
					flag = false;
					break;
				}
			}
		}

		// 각 칸에 대하여 체크
		if (flag)
		{
			unordered_map<int, int> m;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					m[board[i][j]]++;
				}
			}
			if (m.size() != 9)
			{
				flag = false;				
			}
			m.clear();

			for (int i = 0; i < 3; i++)
			{
				for (int j = 3; j < 6; j++)
				{
					m[board[i][j]]++;
				}
			}
			if (m.size() != 9)
			{
				flag = false;				
			}
			m.clear();

			for (int i = 0; i < 3; i++)
			{
				for (int j = 6; j < 9; j++)
				{
					m[board[i][j]]++;
				}
			}
			if (m.size() != 9)
			{
				flag = false;				
			}
			m.clear();

			for (int i = 3; i < 6; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					m[board[i][j]]++;
				}
			}
			if (m.size() != 9)
			{
				flag = false;				
			}
			m.clear();

			for (int i = 3; i < 6; i++)
			{
				for (int j = 3; j < 6; j++)
				{
					m[board[i][j]]++;
				}
			}
			if (m.size() != 9)
			{
				flag = false;				
			}
			m.clear();

			for (int i = 3; i < 6; i++)
			{
				for (int j = 6; j < 9; j++)
				{
					m[board[i][j]]++;
				}
			}
			if (m.size() != 9)
			{
				flag = false;				
			}
			m.clear();

			for (int i = 6; i < 9; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					m[board[i][j]]++;
				}
			}
			if (m.size() != 9)
			{
				flag = false;				
			}
			m.clear();

			for (int i = 6; i < 9; i++)
			{
				for (int j = 3; j < 6; j++)
				{
					m[board[i][j]]++;
				}
			}
			if (m.size() != 9)
			{
				flag = false;				
			}
			m.clear();

			for (int i = 6; i < 9; i++)
			{
				for (int j = 6; j < 9; j++)
				{
					m[board[i][j]]++;
				}
			}
			if (m.size() != 9)
			{
				flag = false;				
			}
			m.clear();
		}

		cout << "#" << test_case << " ";
		if (flag)
			cout << 1;
		else
			cout << 0;

		cout << '\n';
	}

	return 0;
}