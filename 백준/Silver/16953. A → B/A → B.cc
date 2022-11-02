#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// bfs
long A, B;
unordered_map<long, long> m;

int main()
{
    cin >> A >> B;

    queue<long> q;
    q.push(A);
    m[A] = 1;

    while (!q.empty())
    {
        long pos = q.front();        
        q.pop();

        // 현재 방문하지 않은 경우와 방문한 경우
        if (pos*2 <= B)
        {
            if (m[pos*2] == 0)
            {
                m[pos*2] = m[pos] + 1;
                q.push(pos*2);
            }
            else
            {
                if (m[pos*2] > m[pos] + 1)
                {
                    m[pos*2] = m[pos] + 1;
                    q.push(pos*2);
                }
            }
        }
        if (pos*10+1 <= B)
        {
            if (m[pos*10+1] == 0)
            {
                m[pos*10+1] = m[pos] + 1;
                q.push(pos*10+1);
            }
            else
            {
                if (m[pos*10+1] > m[pos] + 1)
                {
                    m[pos*10+1] = m[pos] + 1;
                    q.push(pos*10+1);
                }
            }
        }
    }

    if (m[B] == 0)
        m[B] = -1;

    cout << m[B];    
    
}