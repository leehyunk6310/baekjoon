#include <iostream>
#include <string>
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
		int index = 65;
		int N;
		int cnt = 0;		
		vector<string> v;

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			v.push_back(s);			
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < N; i++)
		{
			if (v[i][0] == index)
			{
				index++;
			}
		}
		
		cout << "#" << test_case << " " << index - 65 << '\n';
	}

	return 0;
}