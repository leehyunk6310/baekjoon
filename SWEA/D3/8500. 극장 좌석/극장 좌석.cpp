#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int t;
		vector<int> v;
		int cnt = 0;

		cin >> t;

		cnt += t;
		for (int i = 0; i < t; i++)
		{
			int n;
			cin >> n;
			v.push_back(n);
		}

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		cnt += v[0];
		for (auto n : v)
			cnt += n;

		cout << "#" << test_case << " " << cnt << '\n';
	}

	return 0;
}