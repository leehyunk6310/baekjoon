#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;		
		int idx = 'a';
		int cnt = 0;
		cin >> s;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == idx)
			{
				idx++;
				cnt++;
			}
			else
				break;
		}

		cout << "#" << test_case << " " << cnt << '\n';
	}

	return 0;
}