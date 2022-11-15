#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s, sortedS;
		unordered_map<string, bool> m;
		bool flag = false;

		cin >> s;
		
		sortedS = s;
		sort(sortedS.begin(), sortedS.end());

		do
		{
			if (sortedS[0] != '0')
				m[sortedS] = true;

		} while (next_permutation(sortedS.begin(), sortedS.end()));

		for (auto mm : m)
		{
			if (stoi(mm.first) % stoi(s) == 0 && stoi(mm.first) / stoi(s) != 1)
			{
				flag = true;
				break;
			}
		}

		cout << "#" << test_case << " ";
		if (flag)
			cout << "possible";
		else
			cout << "impossible";

		cout << '\n';


	}

	return 0;
}