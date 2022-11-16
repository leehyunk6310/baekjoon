#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	string score[10] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		// 점수와 학생 번호를 pair로 가져야한다.
		// 점수순으로 나열해서 몇 등인지 체크한다.
		priority_queue < pair<double, int>> pq;
		
		int number = 1;

		cin >> N >> K;

		for (int i = 0; i < N; i++)
		{
			double sum = 0;
			double s1, s2, s3;
			cin >> s1 >> s2 >> s3;

			sum += s1 * 0.35 + s2 * 0.45 + s3 * 0.2;
			pq.push({ sum, number });
			number++;
		}
		// 몇 등인지 체크
		int cnt = 0;
		while (true)
		{
			if (pq.top().second == K)
			{
				break;
			}
			pq.pop();
			cnt++;
		}
		cnt++;

		// 몇 명씩 같은 점수를 줄지 정한다.
		int many = N / 10;

		int idx = 0;
		while (cnt > many)
		{
			cnt -= many;
			idx++;
		}
		cout << "#" << test_case << " " << score[idx] << '\n';
		
	}

	return 0;
}