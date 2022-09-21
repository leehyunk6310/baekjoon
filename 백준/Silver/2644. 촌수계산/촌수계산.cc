#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 부모 <-> 자식 1촌
// 나 <-> 아버지 형제 3촌
// bfs

int main()
{
    int n;
    int from, to;
    int m;
    vector<vector<int>> v(101, vector<int>(101, 0));
    vector<bool> visited(101, 0);
    queue<int> q;
    int dist = 0;
    int curr;
        
    cin >> n;
    cin >> from >> to;
    cin >> m;
    for (int i=0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;

        v[x][y] = 1;
        v[y][x] = 1;
    }

    q.push(from);
    visited[from] = true;
    while (!q.empty())
    {
        int qSzie = q.size();
         
        for (int i=0; i<qSzie; i++)
        {
            curr = q.front();
            if (curr == to)
                break;
            visited[curr] = true;
            for (int j=1; j<=n; j++)
            {
                if (v[curr][j] != 0 && !visited[j])
                {
                    q.push(j);
                }
            }
            q.pop();
        }
        if (curr == to)
            break;
        dist++;
        
        
    }

    if (q.empty())
        cout << -1;
    else
        cout << dist;
    
    
}