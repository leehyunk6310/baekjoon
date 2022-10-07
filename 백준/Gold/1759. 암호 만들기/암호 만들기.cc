#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;

vector<string> list;
vector<string> answers;

void permute(string s)
{
    vector<bool> v(L, false);
    while (v.size() < C)
        v.push_back(true);

    do
    {
        string str = "";
        for (int i=0; i<s.size(); i++)
        {
            if (!v[i])
                str += s[i];
        }
        sort(str.begin(), str.end());        
        answers.push_back(str);
    } while (next_permutation(v.begin(), v.end()));
    
}
// 최소 한 개의 모음, 최소 두 개의 자음
bool check(string s)
{
    int cnt1 = 0;
    int cnt2 = 0;

    for (auto ch : s)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            cnt1++;
        else
            cnt2++;

        
        if (cnt1 >= 1 && cnt2 >= 2)
            return true;
        
        
    }
    return false;
}
int main()
{
    string s = "";
    cin >> L >> C;
    for (int i=0; i<C; i++)
    {
        char c;
        cin >> c;
        s += c;
    }    
    permute(s);

    sort(answers.begin(), answers.end());

    for (auto str : answers)
    {
        if (check(str))
        {
            list.push_back(str);            
        }
    }

    for (auto str : list)
        cout << str << endl;
}