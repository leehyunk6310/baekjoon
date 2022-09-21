#include <iostream>
#include <vector>
using namespace std;
// 1 땅, 0 바다
int w, h;
vector<vector<int>> g(51, vector<int>(51, 0));
vector<vector<bool>> visited(51, vector<bool>(51, false));
vector<int> answer;
int land = 0;

// 동서남북 및 대각선 이동 실시
void DFS(int row, int col)
{
    if (row<0 || col<0 || row>h || col>w)
        return;
    if (visited[row][col])
        return;
    else if(g[row][col] == 1)
    {
        visited[row][col] = true;
        DFS(row, col+1);
        DFS(row, col-1);
        DFS(row+1, col);
        DFS(row-1, col);
        DFS(row-1, col-1);
        DFS(row-1, col+1);
        DFS(row+1, col-1);
        DFS(row+1, col+1);
    }
}

int main()
{
    while (true)
    {
        land = 0;
        cin >> w >> h;
        //탈출 조건
        if (w == 0 && h == 0)
            break;
        // 초기화 (그래프 0으로 초기화 후 값 대입, visited초기화)
        for (int i=0; i<h; i++)
        {
            for (int j=0; j<w; j++)
            {                
                g[i][j] = 0;
            }
        }
        for (int i=0; i<h; i++)
        {
            for (int j=0; j<w; j++)
            {
                int num;
                cin >> num;
                g[i][j] = num;
            }
        }
        for (int i=0; i<h; i++)
        {
            for (int j=0; j<w; j++)
            {                
                visited[i][j] = 0;
            }
        }
        // DFS 실시
        for (int row=0; row<h; row++)
        {
            for (int col=0; col<w; col++)
            {
                if (!visited[row][col] && g[row][col] == 1)
                    {
                        DFS(row, col);
                        land++;
                    }
            }
        }
        answer.push_back(land);
    }
    
    for (auto n : answer)
        cout << n << endl;
}