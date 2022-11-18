#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int test_case;
	int T;
	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int t;
		bool flag = true;
		queue<int> q;

		cin >> t;
		for (int i = 0; i <8; i++)
		{
			int n;
			cin >> n;
			q.push(n);
		}

		while (1)
		{
			for (int i = 1; i <= 5; i++)
			{
				int num = q.front();
				if (num - i > 0)
				{
					q.pop();
					q.push(num - i);
				}
				else
				{
					q.push(0);
					q.pop();
					flag = false;
					break;
				}
			}

			if (!flag)
				break;
		}

		cout << "#" << t << " ";
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << '\n';
	}

	return 0;
}