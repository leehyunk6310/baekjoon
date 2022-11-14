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
		bool flag = true;

		cin >> revs;

		s = revs;
		reverse(revs.begin(), revs.end());

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == revs[i])
				continue;
			if (s[i] == '?' || revs[i] == '?')
				continue;

			flag = false;
		}

		if (flag)
			cout << "#" << test_case << " " << "Exist\n";
		else
			cout << "#" << test_case << " " << "Not exist\n";
	}

	return 0;
}