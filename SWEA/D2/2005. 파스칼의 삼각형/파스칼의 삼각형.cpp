#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		vector<vector<int>> v;

		v.push_back({ 1 });
		v.push_back({ 1,1 });

		cin >> N;

		// 각 행에 대해서
		for (int i = 2; i <= N; i++)
		{
			vector<int> tmp(1, 1);

			int row = i - 1;

			for (int j = 0; j < v[row].size() - 1; j++)
			{
				tmp.push_back(v[row][j] + v[row][j + 1]);
			}
			tmp.push_back(1);

			v.push_back(tmp);
		}

		cout << "#" << test_case << '\n';
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}