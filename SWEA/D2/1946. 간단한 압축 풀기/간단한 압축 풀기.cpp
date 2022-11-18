#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		string s = "";
		int cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			char ch;
			int n;
			

			cin >> ch >> n;			

			for (int j = 0; j < n; j++)
			{
				s += ch;
				cnt++;
				if (cnt == 10)
				{
					cnt = 0;
					s += '\n';
				}
			}
			
		}
		cout << "#" << test_case << "\n";
		cout << s << '\n';
	}

	return 0;
}