#include <iostream>
using namespace std;
// 1]
// 첫 문자와 같은 문자들을 뒤집는 경우
// 2]
// 첫 문자와 다른 문자들을 뒤집는 경우
string s;
int answer = 1e9;
int count = 0;
char before;

int main()
{
    cin >> s;

    for (int i=0; i<s.size(); i++)
    {
        if (i > 1 && s[i] == s[i-1])
            continue;
        if (s[i] != s[0])
            count++;
    }
    if (answer > count)
        answer = count;
    count=0;

    for (int i=0; i<s.size(); i++)
    {
        if (i > 1 && s[i] == s[i-1])
            continue;
        if (s[i] == s[0])
            count++;
    }
    if (answer > count)
        answer = count;
    count=0;
    cout << answer;
        
}