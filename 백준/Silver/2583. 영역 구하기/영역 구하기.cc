#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;    // 행, 열
int graph[101][101] = {0, };
int range = 0;
int cnt = 1;
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
vector<int> cntVec;
// 해당 칸의 graph값을 -1로 변경
// 0,0 부터 M-1,N-1까지 탐색한다. 방문시 1로 변경하며 cnt값을 증가
// 탐색은 상하좌우로 한다.
void BFS(int row, int col)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    graph[row][col] = 1;
    cnt = 1;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        // cout << p.first << " " << p.second;
        for (int i=0; i<4; i++)
        {
            // 방문 가능하면
            if (p.first + dr[i] >= 0 && p.first + dr[i] < M && p.second + dc[i] >= 0 && p.second + dc[i] < N && graph[p.first + dr[i]][p.second + dc[i]] == 0)
            {
                q.push({p.first + dr[i], p.second + dc[i]});
                graph[p.first + dr[i]][p.second + dc[i]] = 1;
                cnt++;
            }
        }
        q.pop();
    }
    // 방문 다 했을 때 영역추가
    range++;
    cntVec.push_back(cnt);
}

int main()
{
    cin >> M >> N >> K;
    for (int i=0; i<K; i++)
    {
        int c1, r1, c2, r2;
        cin >> c1 >> r1 >> c2 >> r2; // 열, 행으로 입력

        for (int r=r1; r<r2; r++)
        {
            for (int c=c1; c<c2; c++)
            {
                graph[r][c] = -1;
            }
        }
    }
    // 탐색 실시
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (graph[i][j] == 0)
                BFS(i, j);
        }
    }
    sort(cntVec.begin(), cntVec.end());
    
    cout << range << endl;
    for (auto n : cntVec)
        cout << n << " ";
    
}