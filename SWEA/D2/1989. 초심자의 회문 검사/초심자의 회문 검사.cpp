#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s, revs;
		cin >> s;
		revs = s;
		reverse(revs.begin(), revs.end());

		cout << "#" << test_case << " ";
		if (s == revs)
			cout << 1;
		else
			cout << 0;
		cout << '\n';

	}

	return 0;
}