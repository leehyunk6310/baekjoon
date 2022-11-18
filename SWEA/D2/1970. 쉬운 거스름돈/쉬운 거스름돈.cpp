#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{				
		int money;
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt3 = 0;
		int cnt4 = 0;
		int cnt5 = 0;
		int cnt6 = 0;
		int cnt7 = 0;
		int cnt8 = 0;
		cin >> money;
		
		if (money >= 50000)
		{
			cnt1 += money / 50000;
			money -= cnt1 * 50000;
		}
		if (money >= 10000)
		{
			cnt2 += money / 10000;
			money -= cnt2 * 10000;
		}
		if (money >= 5000)
		{
			cnt3 += money / 5000;
			money -= cnt3 * 5000;
		}
		if (money >= 1000)
		{
			cnt4 += money / 1000;
			money -= cnt4 * 1000;
		}
		if (money >= 500)
		{
			cnt5 += money / 500;
			money -= cnt5 * 500;
		}
		if (money >= 100)
		{
			cnt6 += money / 100;
			money -= cnt6 * 100;
		}
		if (money >= 50)
		{
			cnt7 += money / 50;
			money -= cnt7 * 50;
		}
		if (money >= 10)
		{
			cnt8 += money / 10;
			money -= cnt8 * 10;
		}

		cout << "#" << test_case << "\n" << cnt1 << " "<< cnt2 << " " << cnt3 << " " << cnt4 << " " << cnt5 << " " << cnt6 << " " << cnt7 << " " << cnt8 << '\n';
	}

	return 0;
}