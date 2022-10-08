#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<string> v;
vector<string> answers;
// 스택 문제
int main()
{
    while (1)
    {
        string s = "";
        stack<char> st;
        while (1)
        {
            getline(cin, s);    // 한 줄씩 받아서 s에 넣는다.

            if (s.size() == 1)
                break;
            v.push_back(s);
        }
        if (s.size() == 1)
            break;
        
    }
    
    for (auto s : v)
    {
        stack<char> st;
        bool flag = true;
        for (auto ch : s)
        {
            if (ch == '(')
                st.push('(');
            else if (ch == '[')
                st.push('[');
            else if (ch == ')')
            {
                if (st.empty())
                {
                    flag = false;
                    break;
                }
                else if (st.top() != '(')
                {
                    flag = false;
                    break;
                }
                else
                    st.pop();
            } 
            else if (ch == ']')
            {
                if (st.empty())
                {
                    flag = false;
                    break;
                }
                else if (st.top() != '[')
                {
                    flag = false;
                    break;
                }
                else
                    st.pop();
            } 
        }

        if (!flag || !st.empty())
            answers.push_back("no");
        else
            answers.push_back("yes");
    }

    for (auto ans : answers)
        cout << ans << endl;
}