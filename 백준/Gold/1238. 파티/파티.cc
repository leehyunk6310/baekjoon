#include <iostream>
#include <vector>
using namespace std;

int N, M, X;    // N명 학생, M개의 도로, X마을로 이동
int maxDistance = 0;
vector<vector<int>> graph(1001, vector<int>(1001, 1e9));
// 플로이드 와샬 알고리즘?
int main()
{
    cin >> N >> M >> X;

    // 그래프 초기화
    for (int i=1; i<=N; i++)
    {
        graph[i][i] = 0;
    }
    // 거리값 초기화
    for (int j=0; j<M; j++)
    {
        int from, to, val;
        cin >> from >> to >> val;
        graph[from][to] = val;
    }
    // 플로이드 와샬
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            for (int k=1; k<=N; k++)
            {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    for (int i=1; i<=N; i++)
    {        
        if (graph[i][X] + graph[X][i] > maxDistance)
            maxDistance = graph[i][X] + graph[X][i];
    }

    cout << maxDistance;
}