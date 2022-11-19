#include <iostream>
using namespace std;

// 1부터 시작해서 쭈욱 더하면서 해당 값이 N을 넘기전에 N이 되면 cnt에 추가한다.
// 다음은 2, 3, 4,. .. 부터 시작한다.
int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, cnt = 0;
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			int sum = 0;
			for (int j = i; j <= N; j++)
			{
				sum += j;
				if (sum == N)
					cnt++;
				if (sum > N)
					break;
			}
		}

		cout << "#" << test_case<< " " << cnt << '\n';
	}

	return 0;
}