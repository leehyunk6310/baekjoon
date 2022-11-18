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
	// 앞에서부터 2개씩 찍어서 스왑해본다.
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		vector<int> v;

		cin >> s;
		// 1자리 인 경우
		if (s.size() == 1)
		{
			cout << "#" << test_case << " " << stoi(s) << " " << stoi(s) << '\n';
		}
		else
		{
			v.push_back(stoi(s));
			// 두 자리 이상인 경우
			for (int i = 0; i < s.size()-1; i++)
			{
				for (int j = i + 1; j < s.size(); j++)
				{
					string tmp = s;
					// 같은 값이거나 첫번째 숫자랑 0은 교환x
					if (i == 0 && tmp[j] == '0' || tmp[i] == tmp[j])
						continue;
					swap(tmp[i], tmp[j]);
					v.push_back(stoi(tmp));
				}
			}
			sort(v.begin(), v.end());

			cout << "#" << test_case << " " << v.front() << " " << v.back() << '\n';
		}
	}

	return 0;
}