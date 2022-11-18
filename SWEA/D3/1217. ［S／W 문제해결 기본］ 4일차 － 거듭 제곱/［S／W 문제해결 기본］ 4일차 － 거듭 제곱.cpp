#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T=10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int t, A, B, num=1;
		cin >> t;
		cin >> A >> B;

		for (int i = 0; i < B; i++)
		{
			num *= A;
		}

		cout << "#" << test_case << " " << num << '\n';
	}

	return 0;
}