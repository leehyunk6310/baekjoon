#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> maps(8, vector<int>(8, 0));
int answer = -1;
// 0, 안전지역의 넓이를 구해야한다. 
int check(vector<vector<int>> map)
{
    int cnt = 0;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            // 0의 갯수를 체크한다.
            if (map[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

// 바이러스는 상하좌우로 퍼진다. (bfs)
void bfs()
{
    vector<vector<int>> tmp = maps;    
    queue<pair<int, int>> q;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
            if (tmp[i][j] == 2)
                q.push({i, j});
    }

    while (!q.empty())
    {
        int qSize = q.size();
        for (int i=0; i<qSize; i++)
        {
            pair<int, int> pos = q.front();
            int row = pos.first;
            int col = pos.second;

            // 상하좌우 체크
            if (row-1 >= 0)
            {
                if (tmp[row-1][col] == 0)
                {
                    q.push({row-1, col});
                    tmp[row-1][col] = 2;
                }
            }            
            if (row+1 < N)
            {
                if (tmp[row+1][col] == 0)
                {
                    q.push({row+1, col});
                    tmp[row+1][col] = 2;
                }
            }
            if (col-1 >= 0)
            {
                if (tmp[row][col-1] == 0)
                {
                    q.push({row, col-1});
                    tmp[row][col-1] = 2;
                }
            }
            if (col+1 < M)
            {
                if (tmp[row][col+1] == 0)
                {
                    q.push({row, col+1});
                    tmp[row][col+1] = 2;
                }
            }
            q.pop();
        }
    }

    // 체크한다.
    answer = max(answer, check(tmp));
    
}
// 무작위로 3개의 벽을 세워야 한다. (bruteforce)
// 0인 지역에 벽을 세울 수 있다. (backtracking)
void Wall(int cnt)
{
    if (cnt == 3)
    {
        bfs();
        return;
    }

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            if (maps[i][j] == 0)
            {
                maps[i][j] = 1;
                Wall(cnt+1);
                maps[i][j] = 0;
            }
        }
    }
}

int main()
{
    // 지도 초기화
    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
            cin >> maps[i][j];
    }

    // 무작위로 벽을 세운다.
    // 3개를 세우고 bfs를 실시한다.
    // bfs가 끝나면 check를 한다.
    Wall(0);    

    cout << answer;
}