#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int T;
string s;
vector<string> v;
int main()
{
    cin >> T;
    for (int i=0; i<T; i++)
    {
        cin >> s;
        stack<char> st;
        bool flag = true;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i] == '(')
                st.push('(');
            else if (s[i] == ')' && st.empty())
            {
                flag = false;
                break;
            }
            else
                st.pop();
        }

        if (flag && st.empty())
            v.push_back("YES");
        else
            v.push_back("NO");
    }

    for (auto str : v)
        cout << str << endl;
}