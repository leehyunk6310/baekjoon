#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, k=1, answer;
		set<char> s;

		cin >> N;

		while (1)
		{			

			int num = N * k;
			string str = to_string(num);
			for (auto ch : str)
				s.insert(ch);

			if (s.size() == 10)
			{
				answer = num;
				break;
			}
			k++;
		}

		cout << "#" << test_case << " " << answer << "\n";
	}

	return 0;
}