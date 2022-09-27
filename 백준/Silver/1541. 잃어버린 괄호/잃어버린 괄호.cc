#include <iostream>
using namespace std;

string s;
string temp = "";
int sum = 0;
char op = '+';
// 최소 값을 도출해내야함
// -를 기준으로 괄호를 여닫아야한다
// -가 나왔는데 +가 나오는 경우 -가 나올때까지 합산
// -가 나왔는데 뒤에서 -가 나오는 경우 그 앞에서 계산을 마무리한다.
// ==> -가 나오는 순간부터 뒤의 값은 다 음수로 바꾸면 된다.
int main()
{
    cin >> s;

    if (s[0] == '-')
        op = '-';

    for (int i=0; i<s.size(); i++)
    {   
        // 숫자 생성
        if (s[i] != '+' && s[i] != '-')
        {
            temp += s[i];
        }
        // +해주는 경우
        else if ((s[i] == '+' || s[i] == '-') && op == '+')
        {
            sum += stoi(temp);
            // op를 -로 변경
            if (s[i] == '-' && op == '+')
            {
                op = '-';
            }
            temp = "";
        }
        else if ((s[i] == '+' || s[i] == '-') &&op == '-')
        {
            sum -= stoi(temp);
            temp = "";
        }
    }
    // 마지막 문자열에 대한 처리
    if (op == '-')
    {
        sum -= stoi(temp);
        temp = "";
    }
    else
    {
        sum += stoi(temp);
        temp = "";
    }

    cout << sum << endl;
}