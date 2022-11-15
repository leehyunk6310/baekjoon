#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	// 매 초마다 남는 붕어빵의 개수를 고려한다

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M, K;	// N명, M초마다 K개 붕어빵		
		int boong[11112] = { 0, };
		bool flag = true;
		unordered_map<int, int> m;
		priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int,int>>> pq;

		cin >> N >> M >> K;		

		// 붕어빵 개수 적용
		for (int i = 0; i < 11112; i++)
		{
			boong[i] = i / M * K;
		}
		// 몇 초에 몇명이 기다리고 있는지 체크
		for (int i = 0; i < N; i++)
		{
			int s;
			cin >> s;
			m[s]++;
		}
		// pq를 써서 시간이 가장 적게 걸리는 초부터 고려.
		for (auto mm : m)
		{
			pq.push({ mm.first, mm.second });
		}

		while (!pq.empty())
		{
			int sec = pq.top().first;
			int cnt = pq.top().second;

			pq.pop();

			if (boong[sec] < cnt)
			{
				flag = false;
				break;
			}
			else
			{
				for (int i = sec; i < 11112; i++)
				{
					boong[i] -= cnt;
				}
			}
		}
	
		cout << "#" << test_case << " ";
		if (flag)
			cout << "Possible";
		else
			cout << "Impossible";

		cout << '\n';
	}

	return 0;
}