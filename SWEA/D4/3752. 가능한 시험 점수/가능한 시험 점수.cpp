#include <iostream>
#include <vector>
using namespace std;

int arr[100];

int main()
{
	int test_case;
	int T;
	cin >> T;
	 
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, idx = 1;
		bool visited[100001] = { false, };
		vector<int> v;

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		v.push_back(0);
		v.push_back(arr[0]);
		visited[0] = true;
		visited[arr[0]] = true;

		while (true)
		{
			if (idx == N)
				break;
			int vSize = v.size();

			for (int i = 0; i < vSize; i++)
			{
				int score1 = v[i] + 0;
				int score2 = v[i] + arr[idx];

				if (!visited[score1])
				{
					v.push_back(score1);
					visited[score1] = true;
				}
				if (!visited[score2])
				{
					v.push_back(score2);
					visited[score2] = true;
				}
			}
			idx++;

			
		}
		
		cout << "#" << test_case << " " << v.size() << '\n';

	}

	return 0;
}