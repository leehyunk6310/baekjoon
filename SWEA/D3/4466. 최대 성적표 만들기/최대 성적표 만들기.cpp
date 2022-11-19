#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K, sum=0;
		vector<int> v;

		cin >> N >> K;
		for (int i = 0; i < N; i++)
		{
			int n;
			
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
        
		for (int i = 0; i < K; i++)
		{
			sum += v[i];
		}

		cout << "#" << test_case << " " << sum << '\n';
	}

	return 0;
}