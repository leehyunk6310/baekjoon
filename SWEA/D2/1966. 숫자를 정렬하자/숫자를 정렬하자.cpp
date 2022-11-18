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
		int N;
		vector<int> v;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int n;
			cin >> n;
			v.push_back(n);
		}

		sort(v.begin(), v.end());
		

		cout << "#" << test_case << " ";
		for (auto num : v)
			cout << num << " ";
		cout << '\n';

	}

	return 0;
}