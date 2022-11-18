#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int test_case;
	int T = 10;	

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		char c;
		vector<char> v;

		cin >> N;

		cin >> c;
		v.push_back(c);

		for (int i = 1; i < N; i++)
		{
			cin >> c;
			if (v.back() == c)
				v.pop_back();
			else
				v.push_back(c);
		}

		cout << "#" << test_case << " ";
		for (auto ch : v)
			cout << ch;
		cout << '\n';
	}

	return 0;
}