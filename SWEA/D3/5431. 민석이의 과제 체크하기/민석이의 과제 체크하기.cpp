#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		bool arr[101] = { false, };

		cin >> N >> K;
		for (int i = 0; i < K; i++)
		{
			int num;
			cin >> num;
			arr[num] = true;
		}

		cout << "#" << test_case << " ";
		for (int i = 1; i <= N; i++)
		{
			if (!arr[i])
				cout << i << " ";
		}
		cout << '\n';
	}

	return 0;
}