#include <iostream>
using namespace std;

string s = "";
string bomb = "";
string answer = "";
int main()
{
    cin >> s;
    cin >> bomb;

    for (auto ch : s)
    {
        // 폭탄의 마지막 글자를 발견한 경우 폭탄이 있는지 계산
        answer += ch;

        if (answer.back() == bomb.back())
        {
            if (answer.size() < bomb.size())
                continue;
            if (answer.substr(answer.size() - bomb.size(), bomb.size()) == bomb)
            for (int i=0; i<bomb.size(); i++)
                answer.pop_back();
        }        
    }
    
    if (answer == "")
        cout << "FRULA";
    else
        cout << answer;
}