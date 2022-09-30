#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;    // N 도시, M 여행 계획에 속한 도시
int graph[201][201] = {0, };
vector<bool> visited(201, false);
int route[1001] = {0, };
int start, dest;
// BFS로 접근
bool BFS(int start, int dest, vector<bool> visited)
{
    queue<int> q;
    visited[start] = true;  // 방문 처리
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i=0; i<qSize; i++)
        {
            int qfront = q.front();
            if (qfront == dest) // 경로가 있으면 true 반환
                
                return true;

            for (int j=1; j<=N; j++)
            {
                if (graph[qfront][j] != 0 && !visited[j])   // 연결되고 방문하지 않았으면
                {
                    q.push(j);
                    visited[j] = true;
                }
            }
            q.pop();
        }
    }
    return false;  
}

int main()
{
    cin >> N;
    cin >> M;
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int i=0; i<M; i++)
    {
        cin >> route[i];
    }
    // 매 start, dest를 검사한다.
    for (int i=0; i<M-1; i++)
    {
        if (!BFS(route[i], route[i+1], visited))
        {
            cout << "NO";
            break;
        }
        if (i == M-2)
            cout << "YES";
    }
}