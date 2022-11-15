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
		unordered_map<int, int> m;
		int N;
		bool flag = true;

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int n;
			cin >> n;
			m[n]++;
		}

		for (auto mm : m)
		{
			if (mm.second != 1)
			{
				flag = false;
				break;
			}
		}

		cout << "#" << test_case << " ";
		if (flag)
			cout << "Yes";
		else
			cout << "No";

		cout << '\n';
	}

	return 0;
}