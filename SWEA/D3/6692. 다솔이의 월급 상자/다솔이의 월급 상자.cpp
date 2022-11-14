#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	cout << fixed;
	cout.precision(6);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		double avg = 0;

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			double p, x;

			cin >> p >> x;

			avg += p * x;
		}

		cout << "#" << test_case << " " << avg << '\n';
	}

	return 0;
}