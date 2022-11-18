#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int h1, h2, m1, m2;
		int hour, miniute;

		cin >> h1 >> m1 >> h2 >> m2;

		hour = h1 + h2;
		miniute = m1 + m2;
		if (miniute >= 60)
		{
			hour++;
			miniute -= 60;
		}

		if (hour >= 13)
		{
			hour -= 12;
		}

		cout << "#" << test_case << " " << hour << " " << miniute << "\n";
	}

	return 0;
}