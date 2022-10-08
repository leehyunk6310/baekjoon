#include <iostream>
#include <queue>
using namespace std;

int N;
int main()
{
    queue<int> q;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (s == "front")
        {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.front() << endl;
        }
        else if (s == "back")
        {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.back() << endl;
        }
        else if (s == "size")
        {
            cout << q.size() << endl;
        }
        else if (s == "empty")
        {
            if (q.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (s == "pop")
        {
            if (q.empty())
                cout << -1 << endl;
            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
}