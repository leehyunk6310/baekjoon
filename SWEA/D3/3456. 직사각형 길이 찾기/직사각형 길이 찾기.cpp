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

		for (int i = 0; i < 3; i++)
		{
			int num;
			cin >> num;

			m[num]++;
		}

		cout << "#" << test_case << " ";
		for (auto mm : m)
		{
			if (mm.second %2 == 1)
				cout << mm.first << '\n';			
		}
	}

	return 0;
}