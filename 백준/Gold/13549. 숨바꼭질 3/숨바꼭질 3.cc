#include <iostream>
#include <queue>
using namespace std;

// 순간이동은 0초, 2*X의 위치로 이동
// 그냥 이동은 1초, X+1 또는 X-1로 이동
// dp?
int visited[100001] = {0, };

int main()
{
    int from, to;
    cin >> from >> to;
    for (int i=0; i<100001; i++)
        visited[i] = -1;

    visited[from] = 1;


    queue<int> q;
    q.push(from);

    while (!q.empty())
    {
        int pos = q.front();        
        q.pop();

        // 각 경우에 대하여 방문하지 않았던 경우, 방문한 경우로 나눈다.
        if (pos-1 >= 0)
        {
            if (visited[pos-1] == -1)
            {
                visited[pos-1] = visited[pos] + 1;
                q.push(pos-1);
            }
            else
            {
                if (visited[pos-1] > visited[pos] + 1)
                {
                    visited[pos-1] = visited[pos] + 1;
                    q.push(pos-1);
                }
            }
        }
        if (pos+1 <= 100000)
        {
            if (visited[pos+1] == -1)
            {
                visited[pos+1] = visited[pos] + 1;
                q.push(pos+1);
            }
            else
            {
                if (visited[pos+1] > visited[pos] + 1)
                {
                    visited[pos+1] = visited[pos] + 1;
                    q.push(pos+1);
                }
            }
        }
        if (pos*2 <= 100000)
        {
            if (visited[pos*2] == -1)
            {
                visited[pos*2] = visited[pos];
                q.push(pos*2);
            }
            else
            {
                if (visited[pos*2] > visited[pos])
                {
                    visited[pos*2] = visited[pos];
                    q.push(pos*2);
                }
            }
        }
    }
    
    cout << visited[to]-1;
}