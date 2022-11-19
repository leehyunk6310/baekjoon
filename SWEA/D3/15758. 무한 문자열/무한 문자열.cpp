#include <iostream>
#include <string>
using namespace std;

// 서로 길이가 같을 때까지 반복해놓고 같은 문자열이면 될듯?
int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s1, s2;
		string t1, t2;

		cin >> s1 >> s2;

		t1 = s1;
		t2 = s2;

		cout << "#" << test_case << " ";
		if (s1.size() != s2.size())
		{
			for (int i = 0; i < t2.size()-1; i++)
			{
				s1 += t1;
			}
			for (int j = 0; j < t1.size()-1; j++)
			{
				s2 += t2;
			}

			if (s1 == s2)
				cout << "yes" << '\n';
			else
				cout << "no" << '\n';
		}
		else
		{
			if (s1 == s2)
				cout << "yes" << '\n';
			else
				cout << "no" << '\n';
		}
	}

	return 0;
}