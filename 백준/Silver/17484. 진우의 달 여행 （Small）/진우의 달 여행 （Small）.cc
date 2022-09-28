#include <iostream>
#include <vector>
using namespace std;

int N, M;
int g[7][7];
int answer = 1e9;
// 처음에는 M개 중 한 곳으로 이동
// 이후 left, straight, right 방향 중 택1 해서 이동
void DFS(int dist, vector<bool> dir, int row, int col, int prev)
{
    // 거리 도달시
    if (row >= N)
    {
        answer = min(answer, dist);
        return;
    }

    // 열을 벗어나는 경우
    if (col < 0 || col >= M)
    {
        return;
    }
    else
    {
        // cout << "dist : " << dist << endl;
        dist += g[row][col];
    }

    // 방향을 고려한다.
    for (int i=0; i<3; i++)
    {
        if (prev == i)
        {
            dir[i] = true;
        }
        else
        {
            dir[i] = false;
        }
    }
    for (int i=0; i<3; i++)
    {
        if (!dir[i] && i == 0)
        {
            DFS(dist, dir, row+1, col-1, 0);
        }
        if (!dir[i] && i == 1)
        {
            DFS(dist, dir, row+1, col, 1);
        }
        if (!dir[i] && i == 2)
        {
            DFS(dist, dir, row+1, col+1, 2);
        }
    }
}

int main()
{
    int dist = 0;
    vector<bool> dir(3, false);

    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cin >> g[i][j];
        }
    }
    
    for (int i=0; i<M; i++)
    {
        // 거리, 방향, 행, 열
        DFS(dist, dir, 0, i, -1);
    }

    cout << answer;
}