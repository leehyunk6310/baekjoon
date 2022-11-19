#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int K, answer = 0;
		stack<int> stk;

		cin >> K;

		for (int i = 0; i < K; i++)
		{
			int num;
			cin >> num;

			if (num != 0)
				stk.push(num);
			else
				stk.pop();
		}

		while (!stk.empty())
		{
			answer += stk.top();
			stk.pop();
		}

		cout << "#" << test_case << " " << answer << "\n";
	}

	return 0;
}