#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(101, vector<int>(101, 1e9));
int N;
// 플로이드 와샬
int main()
{
    // 대각선 0 초기화
    cin >> N;
    for (int i=1; i<=N; i++)
        graph[i][i] = 0;

    // 그래프 초기화
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
        {
            int num;
            cin >> num;
            if (num)
                graph[i][j] = num;
        }                      
    // 그래프 갱신
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            for (int k=1; k<=N; k++)
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
    // 경로가 있으면 1로 아니면 0으로 변경
    for (int i=1; i<=N; i++)
    {    
        for (int j=1; j<=N; j++)
        {
            if (graph[i][j] == 1e9)
                graph[i][j] = 0;
            else if (graph[i][j] != 0)
                graph[i][j] = 1;
        }
    }

    // 대칭인 부분이 1이면 원점으로 되돌아 갈 수 있다.
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            if (graph[i][j] == 1)
            {
                if (graph[j][i] == 1)
                    graph[i][i] = 1;
            }
        }
    }
    
    for (int i=1; i<=N; i++)
    {    
        for (int j=1; j<=N; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
}