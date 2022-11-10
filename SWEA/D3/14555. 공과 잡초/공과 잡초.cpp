#include <iostream>
using namespace std;

// 카운트 하는 경우
// (), (|, |)
int main()
{
    int test_case;
	int T;

    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case)
	{
        string s;
        int cnt = 0;
        cin >> s;

        for (int i=0; i<s.size()-1; i++)
        {
            if (s[i] == '(' && s[i+1] == ')')
            {
                cnt++;
                continue;
            }
            if (s[i] == '(' && s[i+1] == '|')
            {
                cnt++;
                continue;
            }
            if (s[i] == '|' && s[i+1] == ')')
            {
                cnt++;
                continue;
            }
        }

        cout << "#" << test_case << " " << cnt << '\n';
    }
    
    return 0;
}