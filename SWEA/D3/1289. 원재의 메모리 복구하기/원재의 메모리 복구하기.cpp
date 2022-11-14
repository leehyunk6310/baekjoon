#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int cnt = 0;
		string s;

		cin >> s;

		bool flag = false;

		for (int i = 0; i < s.size(); i++)
		{
			for (auto ch : s)
			{
				if (!flag && s[i] == '1')
				{
					cnt++;
					flag = true;
				}
				if (flag && s[i] == '0')
				{
					cnt++;
					flag = false;
				}
			}
		}
		
		cout << "#" << test_case << " " << cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}