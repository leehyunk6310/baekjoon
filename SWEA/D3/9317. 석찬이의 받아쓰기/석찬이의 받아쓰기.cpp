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
		int len, cnt = 0;
		string s1;
		string s2;

		cin >> len;
		cin >> s1 >> s2;
		
		for (int i = 0; i < len; i++)
		{			
			if (s1[i] == s2[i])
				cnt++;			
		}

		cout << "#" << test_case << " " << cnt << '\n';
		
	}

	return 0;
}