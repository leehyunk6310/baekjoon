#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	// 처음부터 D만큼 떨어진 곳에 둔다.
	// 이후 그곳으로부터 +D만큼 커버 가능하다.
	// 다음으로 두는 곳은 그곳으로부터 D+1만큼 떨어진다.
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, D;
		int start=1, end, cnt=0;

		cin >> N >> D;
		
		while (1)
		{
			cnt++;
			end = start + 2 * D;
			start = end + 1;

			if (start > N)
				break;
			if (start < N && end >= N)
			{
				cnt++;
				break;
			}
		}
		cout << "#" << test_case << " " << cnt << '\n';
	}	

	return 0;
}