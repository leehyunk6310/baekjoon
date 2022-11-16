#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	// 10 미만은 최대 1, 100미만은 최대 2, 1000미만은 최대 3
	for (test_case = 1; test_case <= T; ++test_case)
	{
		if (test_case < 10)
		{
			if (test_case % 3 == 0)
				cout << "- ";
			else
				cout << test_case << " ";
		}
		else if (test_case < 100)
		{
			int cnt = 0;

			if (test_case / 10 % 3 == 0)
				cnt++;
			if (test_case % 10 % 3 == 0 && test_case % 10 != 0)
				cnt++;

			if (cnt != 0)
			{
				for (int i = 0; i < cnt; i++)
					cout << "-";
				cout << " ";
			}
			else
				cout << test_case << " ";
		}
		else
		{
			int cnt = 0;

			if (test_case / 100 % 3 == 0 && test_case % 100 != 0)
				cnt++;
			if (test_case % 100 / 10 % 3 == 0 && test_case % 100 != 0)
				cnt++;
			if (test_case % 10 % 3 == 0 && test_case % 10 != 0)
				cnt++;

			if (cnt != 0)
			{
				for (int i = 0; i < cnt; i++)
					cout << "-";
				cout << " ";
			}
			else
				cout << test_case << " ";
		}

	}

	return 0;
}