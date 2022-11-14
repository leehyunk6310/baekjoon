#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, Q;
		int arr[1001] = { 0, };
		cin >> N >> Q;

		for (int i = 1; i <= Q; i++)
		{
			int L, R;

			cin >> L >> R;

			for (int j = L; j <= R; j++)
				arr[j] = i;
		}

		cout << "#" << test_case << " ";
		for (int i = 1; i <= N; i++)
			cout << arr[i] << " ";
		cout << '\n';
	}

	return 0;
}