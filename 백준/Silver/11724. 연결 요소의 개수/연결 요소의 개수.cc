#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
int N, M;
vector<vector<int>> g(1001, vector<int>(1001, 1e9));
vector<bool> visited(1001, false);

void DFS(int node)
{
    if (visited[node])
        return;

    visited[node] = true;
    
    for (int i=1; i<=N; i++)
    {
        if (g[node][i] == 1)
        {
            DFS(i);
        }
    }
    
    
}

int main()
{
    
    cin >> N >> M;

    // 대각선 0 초기화
    for (int i=1; i<=N; i++)
    {
        g[i][i] = 0;
    }
    // 연결된 간선은 1로 초기화
    for (int i=0; i<M; i++)
    {
        int u, v;

        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    for (int i=1; i<=N; i++)
    {
        if (!visited[i])
        {
            answer++;
            DFS(i);
        }
    }

    cout << answer;
    
}