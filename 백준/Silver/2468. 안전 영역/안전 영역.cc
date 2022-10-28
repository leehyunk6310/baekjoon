#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 물에 잠기지 않는 최대 영역의 수
// 모든 높이를 고려해서 BFS실시한다.
// 영역의 수를 카운트한다.
int N;
vector<vector<int>> height(100, vector<int>(100, 0));
int maxHeight = -1;
int minHeight = 101;
int answer = 0;
// height 이하인 부분은 0으로 수정
// BFS가 끝난 후 안전 지역 cnt
void BFS(int h)
{
    vector<vector<int>> tmp = height;    
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (tmp[i][j] <= h)
                tmp[i][j] = -1;            
        }
    }

    // 탐색 시작
    // 방문하면 -1로 만든다.    
    int cnt = 0;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (tmp[i][j] != -1)
            {                                
                tmp[i][j] = -1;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty())
                {
                    int qSize = q.size();
                    for (int i=0; i<qSize; i++)
                    {
                        pair<int, int> p = q.front();
                        int row = p.first;
                        int col = p.second;

                        // 동서남북으로 방문가능한지 체크.
                        if (col+1 < N)
                        {
                            if (tmp[row][col+1] != -1)
                            {
                            tmp[row][col+1] = -1;
                            q.push({row, col+1});                        
                            }
                        }
                        if (col-1 >= 0)
                        {
                            {
                                if (tmp[row][col-1] != -1)
                                {
                                tmp[row][col-1] = -1;
                                q.push({row, col-1});                                
                                }
                            }
                        }
                        if (row+1 < N)
                        {
                            if (tmp[row+1][col] != -1)
                            {
                                tmp[row+1][col] = -1;
                                q.push({row+1, col});                                
                            }
                        }
                        if (row-1 >= 0)
                        {
                            if (tmp[row-1][col] != -1)
                            {
                                tmp[row-1][col] = -1;
                                q.push({row-1, col});
                            }
                        }

                        q.pop();
                    }
                }
                cnt++;
            }            
        }
    }
    answer = max(answer, cnt);
}

int main()
{
    cin >> N;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cin >> height[i][j];
            maxHeight = max(maxHeight, height[i][j]);
            minHeight = min(minHeight, height[i][j]);
        }
    }

    for (int i=0; i<=maxHeight; i++)
    {
        BFS(i);
    }

    cout << answer;
    
}