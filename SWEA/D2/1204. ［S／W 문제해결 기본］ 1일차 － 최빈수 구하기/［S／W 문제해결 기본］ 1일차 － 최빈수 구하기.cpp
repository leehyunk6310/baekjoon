#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int t;
		unordered_map<int, int> m;
		priority_queue<int> pq;
		int cntMost = 0;

		cin >> t;

		for (int i = 0; i < 1000; i++)
		{
			int score;
			cin >> score;
			m[score]++;
		}

		for (auto mm : m)
			cntMost = max(cntMost, mm.second);

		for (auto mm : m)
		{
			if (mm.second == cntMost)
				pq.push(mm.first);
		}

		cout << "#" << t << " " << pq.top() << '\n';

	}

	return 0;
}