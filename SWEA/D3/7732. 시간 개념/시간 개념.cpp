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
			string t1, t2;
			long sec1 = 0, sec2 = 0, secDiff;
			cin >> t1 >> t2;
			
			sec1 = stoi(t1.substr(0, 2)) * 60 * 60 + stoi(t1.substr(3, 2)) * 60 + stoi(t1.substr(6, 2));
			sec2 = stoi(t2.substr(0, 2)) * 60 * 60 + stoi(t2.substr(3, 2)) * 60 + stoi(t2.substr(6, 2));
			
			if (sec2 > sec1)
				secDiff = sec2 - sec1;
			else
			{
				secDiff = 24 * 60 * 60 - sec1;
				secDiff += sec2;
			}

			string h, m, s;
			if (secDiff / 3600 < 10)
				h = '0';
			h += to_string(secDiff / 3600);
			secDiff %= 3600;
			if (secDiff / 60 < 10)
				m = '0';
			m += to_string(secDiff / 60);
			secDiff %= 60;
			if (secDiff < 10)
				s = '0';
			s += to_string(secDiff);

			cout << "#" << test_case << " " << h << ":" << m << ":" << s << '\n';		
	}

	return 0;
}