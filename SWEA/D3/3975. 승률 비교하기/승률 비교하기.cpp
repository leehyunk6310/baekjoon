#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		double A, B, C, D;

		cin >> A >> B >> C >> D;

		cout << "#" << test_case << " ";
		if (A / B == C / D)
			cout << "DRAW";
		else if (A / B > C / D)
			cout << "ALICE";
		else
			cout << "BOB";
		
		cout << '\n';

	}

	return 0;
}