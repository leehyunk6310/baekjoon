#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	// 현재 시간을 측정해서 11월 11일 11시 11분과 비교한다.
	for (test_case = 1; test_case <= T; ++test_case)
	{
		long targetMin = 11 + 60 * 11 + 60 * 24 * 11;
		int day, hour, minu;
		cin >> day >> hour >> minu;
		long currMin = minu + 60 * hour + 60 * 24 * day;

		cout << "#" << test_case << " ";

		if (currMin < targetMin)
			cout << -1;
		else
			cout << currMin - targetMin;

		cout << '\n';
	}

	return 0;
}