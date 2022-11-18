#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int P, Q, R, S, W;
		int costA = 0, costB = 0;

		cin >> P >> Q >> R >> S >> W;

		costA += W * P;

		if (W <= R)
		{
			costB += Q;
		}
		else
		{
			costB += Q;
			costB += (W - R)*S;
		}

		cout << "#" << test_case << " " << min(costA, costB) << '\n';
	}

	return 0;
}