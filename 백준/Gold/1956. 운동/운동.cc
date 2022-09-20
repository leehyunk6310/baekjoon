#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(402, vector<int>(402, 1e9));
int main()
{
    int V, E;
    int answer = 1e9;

    cin >> V >> E;

    for (int i=0; i<=V; i++)
    {
        graph[i][i] = 0;
    }

    for (int i=0; i<E; i++)
    {
        int row, col, dist;
        cin >> row >> col >> dist;
        graph[row][col] = dist;
    }

    for (int i=1; i<=V; i++)
    {
        for (int j=1; j<=V; j++)
        {
            for (int k=1; k<=V; k++)
            {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    for (int i=1; i<=V; i++)
    {
        for (int j=1; j<=V; j++)
        {
            if (graph[i][j] == 1e9 || graph[j][i] == 1e9)
                continue;
            if (i != j)
            {
                answer = min(answer, graph[i][j] + graph[j][i]);
            }
        }
        
    }
    cout << (answer == 1e9 ? -1 : answer);
    
}