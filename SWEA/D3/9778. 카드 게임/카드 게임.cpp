#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	// 2 ~ 9의 가치 4장씩, 11의 가치 4장, 10의 가치 16장을 포함한다.
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int cards[12] = { 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 16, 4 };
		int N, sum = 0;
		int go = 0, stop = 0;

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			cards[num]--;
			sum += num;
		}

		for (int i = 2; i < 11; i++)
		{
			if (sum + i > 21)
				stop += cards[i];
			else
				go += cards[i];
		}

		cout << "#" << test_case << " ";
		if (stop >= go)
			cout << "STOP";
		else
			cout << "GAZUA";

		cout << '\n';
	}

	return 0;
}