#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, sum = 0;
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			if (i % 2 == 0)
				sum -= i;
			else
				sum += i;
		}

		cout << "#" << test_case << " " << sum << '\n';
	}

	return 0;
}