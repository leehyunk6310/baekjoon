#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 모든 L에 대하여 BFS를 통해 가장 먼 거리를 갱신해나간다.
int N, M;
vector<vector<int>> maps(51, vector<int>(51, 0));
int answer = 0;

void BFS(int row, int col)
{
    vector<vector<int>> tmp = maps;
    vector<vector<bool>> visited(51, vector<bool>(51, false));

    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;
    while(!q.empty())
    {
        int qSize = q.size();
        for (int i=0; i<qSize; i++)
        {            
            int r = q.front().first;
            int c = q.front().second;

            // 동서남북 탐색 실시
            if (c+1 <= M && tmp[r][c+1] != 0 && !visited[r][c+1])
            {
                visited[r][c+1] = true;
                tmp[r][c+1] = cnt+1;
                q.push({r, c+1});
            }
            if (c-1 >= 1 && tmp[r][c-1] != 0 && !visited[r][c-1])
            {
                visited[r][c-1] = true;
                tmp[r][c-1] = cnt+1;
                q.push({r, c-1});
            }
            if (r+1 <= N && tmp[r+1][c] != 0 && !visited[r+1][c])
            {
                visited[r+1][c] = true;
                tmp[r+1][c] = cnt+1;
                q.push({r+1, c});
            }
            if (r-1 >= 1 && tmp[r-1][c] != 0 && !visited[r-1][c])
            {
                visited[r-1][c] = true;
                tmp[r-1][c] = cnt+1;
                q.push({r-1, c});
            }            
            q.pop();
        }
        cnt++;
    }    

    answer = max(answer, cnt-1);
}

int main()
{
    // L이면 1로 초기화
    cin >> N >> M;
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=M; j++)
        {
            char c;
            cin >> c;
            if (c == 'L')
                maps[i][j] = 1;
        }
    }
    // 모든 L에 대하여 BFS 탐색
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=M; j++)
        {
            if (maps[i][j] == 1)
                BFS(i, j);
        }
    }

    cout << answer;
}