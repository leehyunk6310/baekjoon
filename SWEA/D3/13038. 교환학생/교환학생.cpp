#include <iostream>
#include <algorithm>
using namespace std;

// 0 ~ 6까지 순회하면서 1을 선택하면 해당 날을 기준으로 쭈욱 순회하면서 출석날짜를 줄인다.
// 가장 최소의 날짜를 택한다.
int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, arr[7], answer=1e9;
		
		cin >> N;
		for (int i = 0; i < 7; i++)
			cin >> arr[i];

		for (int i = 0; i < 7; i++)
		{
			int cnt = 0;
			int tmp = N;
			//  시작점을 설정한다.
			if (arr[i] == 1)
			{
				int idx = i;
				tmp--;
				cnt++;
				idx++;
				while (tmp)
				{
					// 해당 인덱스부터 0~6을 계속 순회하면서 N을 줄인다.
					if (idx == 7)
						idx = 0;

					if (arr[idx] == 1)
					{
						tmp--;						
					}
					idx++;
					cnt++;
				}
				
				answer = min(answer, cnt);
			}
		}

		cout << "#" << test_case << " " <<  answer << '\n';
	}

	return 0;
}