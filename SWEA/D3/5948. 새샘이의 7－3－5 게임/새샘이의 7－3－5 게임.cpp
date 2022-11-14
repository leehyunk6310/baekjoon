#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[7] = { false, };
int arr[7];
unordered_map<int, bool> sums;


void dfs(int n, int sum, int cnt, int pos)
{
	if (cnt == 3)
	{		
		sums[sum] = true;
		return;
	}

	for (int i = pos+1; i < 7; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			dfs(i, arr[i] + sum, cnt+1, i);
			visited[i] = false;
		}
	}
}

int main()
{
    
     ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{	
		vector<int> v;

		sums.clear();

		for (int i = 0; i < 7; i++)
		{
			cin >> arr[i];
			visited[i] = false;
		}

		for (int i = 0; i < 7; i++)
		{
			visited[i] = true;
			dfs(i, arr[i], 1, i);
			visited[i] = false;
		}						
		for (auto sum : sums)
			v.push_back(sum.first);

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		cout << "#" << test_case << " " << v[4] << '\n';
	}

	return 0;
}