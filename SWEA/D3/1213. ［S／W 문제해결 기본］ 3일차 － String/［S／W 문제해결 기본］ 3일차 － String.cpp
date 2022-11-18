#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test_case;
	int T;
	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int t, cnt = 0, idx=0;
		string target, original;

		cin >> t >> target >> original;
		

		while (1)
		{			
			int pos = original.find(target);
			if (pos == -1)
				break;			
			original = original.substr(pos + target.size());
			cnt++;
		}
		
		cout << "#" << test_case << " " << cnt << '\n';
	}

	return 0;
}