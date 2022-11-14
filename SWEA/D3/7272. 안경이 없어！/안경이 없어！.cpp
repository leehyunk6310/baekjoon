#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	int arr[26] = { 1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (test_case = 1; test_case <= T; ++test_case)
	{
		bool flag = true;
		string s1, s2;

		cin >> s1 >> s2;

		if (s1.size() != s2.size())
		{
			cout << "#" << test_case << " " << "DIFF\n";
			continue;
		}

		for (int i = 0; i < s1.size(); i++)
		{
			if (arr[s1[i] - 65] != arr[s2[i] - 65])
			{
				flag = false;
				break;
			}
		}

		if (flag)		
			cout << "#" << test_case << " " << "SAME\n";
		else
			cout << "#" << test_case << " " << "DIFF\n";
	}

	return 0;
}