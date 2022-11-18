#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	int day[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int month1, day1, month2, day2;
		int Diff = 0;

		cin >> month1 >> day1 >> month2 >> day2;

		for (int i = month1; i <= month2; i++)
		{
			Diff += day[i];
		}
		Diff  -= day1;
		Diff -= day[month2] - day2;

		cout << "#" << test_case << " " << Diff + 1<< '\n';
	}

	return 0;
}