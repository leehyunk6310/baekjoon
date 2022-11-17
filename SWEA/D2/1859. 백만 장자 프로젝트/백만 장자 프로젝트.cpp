#include <iostream>
using namespace std;

short arr[1000001];

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int idx = 1, maxidx = 1;
		long long buy = 0, sell = 0, cnt = 0;

		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			cin >> arr[i];
			if (arr[maxidx] < arr[i])
				maxidx = i;
		}

		// 처음부터 순회하면서 가장 비쌀때의 idx를 구한다.
		// 해당 idx 전까지 다 구매하고 해당 idx에서 판매한다.
		// 그 이후 idx부터 다시 위의 과정을 반복한다.
		// 만약 maxidx가 idx와 같다면 구매하지 않는다.

		while (1)
		{
			if (idx == N + 1)
				break;
			// maxidx갱신
			for (int i = idx; i <= N; i++)
			{
				if (arr[maxidx] < arr[i])
					maxidx = i;
			}
			// 구매
			for (int i = idx; i < maxidx; i++)
			{
				cnt++;
				buy += arr[i];
			}
			// 판매
			while (cnt != 0)
			{
				sell += arr[maxidx];
				cnt--;
			}
			idx = maxidx + 1;
			maxidx = idx;
		}

		cout << "#" << test_case << " " << sell - buy << '\n';
	}
	
	return 0;
}