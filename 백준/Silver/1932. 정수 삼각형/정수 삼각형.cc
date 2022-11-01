#include <iostream>
using namespace std;

long graph[500][500] = {0, };
int n;
long answer = 0;

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<i+1; j++)
        {
            cin >> graph[i][j];
        }
    }

    if (n == 1)
        cout << graph[0][0];
    else if (n == 2)
    {
        graph[1][0] += graph[0][0];
        graph[1][1] += graph[0][0];
        cout << max(graph[1][0], graph[1][1]);
    }
    else
    {
        graph[1][0] += graph[0][0];
        graph[1][1] += graph[0][0];

        for (int i=2; i<n; i++)
        {
            for (int j=0; j<i+1; j++)
            {
                if (j == 0)
                {
                    graph[i][j] += graph[i-1][j];                    
                }
                else if (j == i)
                {
                    graph[i][j] += graph[i-1][j-1];
                }
                else
                {
                    graph[i][j] += max(graph[i-1][j-1], graph[i-1][j]);
                }
            }
        }

        for (int i=0; i<n; i++)
        {
            answer = max(answer, graph[n-1][i]);
        }
        cout << answer;
    }
    
    
}