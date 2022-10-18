#include <iostream>
#include <vector>
using namespace std;

// DFS, 임의의 정점에서 가장 먼 정점을 찾고, 그정점에 대해서 DFS실시
int V;
vector<pair<int, int>> graph[100001];   // dest, weight
bool visited[100001] = {false, };
int lastNode;
int ans = 0;

// 해당 노드에서 DFS로 탐색
void DFS(int x, int dist)
{
    visited[x] = true;

    if (ans < dist)
    {
        ans = dist;
        lastNode = x;
    }

    for (int i=0; i<graph[x].size(); i++)
    {
        int next_node = graph[x][i].first;
        int next_dist = graph[x][i].second + dist;

        if (!visited[next_node])
        {            
            DFS(next_node, next_dist);
            visited[next_node] = false;
        }
    }
}

int main()
{
    cin >> V;
    // 그래프 초기화
    for (int i=1; i<=V; i++)
    {
        int start;
        cin >> start;
        while (true)
        {
            int dest, val;
            cin >> dest;

            if (dest == -1)
                break;

            cin >> val;
            graph[start].push_back({dest, val});
        }
    }

    DFS(1, 0);
    
    for (int i=1; i<=V; i++)
        visited[i] = false;
    
    DFS(lastNode, 0);
    
    cout << ans;

}