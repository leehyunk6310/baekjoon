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
		string s, s1= "..", s2 = ".", s3 = "#.";

		cin >> s;

		for (int i = 0; i < s.size()-1; i++)
			s1 += "#...";
		s1 += "#..";
		
		for (int i = 0; i < s.size()*2; i++)
			s2 += "#.";

		for (int i = 0; i < s.size(); i++)
		{
			s3 += s[i];
			s3 += ".#.";
		}
		s3.pop_back();

		cout << s1 << '\n' << s2 << '\n' << s3 << '\n' << s2 << '\n' << s1 << '\n';		

	}

	return 0;
}