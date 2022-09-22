#include <iostream>
#include <vector>
using namespace std;

// 적록색약은 R == G로 취급
int N;
char color;
vector<vector<char>> g(101, vector<char>(101, ' '));
vector<vector<bool>> visited1(101, vector<bool>(101, false));
int answer1 = 0;
// 적록색맹용
vector<vector<bool>> visited2(101, vector<bool>(101, false)); 
int answer2 = 0;

void DFS1(int row, int col, char c)
{
    if (row < 0 || col < 0 || row > 101 || col > 101)
        return;
    if (visited1[row][col])
        return;

    // 같은 캐릭터인 경우에만 방문처리하고 탐색
    if (c == g[row][col])
    {
        visited1[row][col] = true;
        // 동서남북으로 탐색
        DFS1(row-1, col, g[row][col]);
        DFS1(row+1, col, g[row][col]);
        DFS1(row, col-1, g[row][col]);
        DFS1(row, col+1, g[row][col]);
    }
}

void DFS2(int row, int col, char c)
{
    if (row < 0 || col < 0 || row > 101 || col > 101)
        return;
    if (visited2[row][col])
        return;

    // 같은 캐릭터인 경우에만 방문처리하고 탐색 || 적색과 녹색이면 탐색
    if (c == g[row][col] || (c == 'R' && g[row][col] == 'G') || (c == 'G' && g[row][col] == 'R'))
    {
        visited2[row][col] = true;
        // 동서남북으로 탐색
        DFS2(row-1, col, g[row][col]);
        DFS2(row+1, col, g[row][col]);
        DFS2(row, col-1, g[row][col]);
        DFS2(row, col+1, g[row][col]);
    }
}

int main()
{
    cin >> N;

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cin >> color;
            g[i][j] = color;
        }
    }

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (!visited1[i][j])
            {
                DFS1(i, j, g[i][j]);
                answer1++;
            }
                
            if (!visited2[i][j])
            {
                DFS2(i ,j, g[i][j]);
                answer2++;
            }
                
        }
    }

    cout << answer1 << "\n" << answer2;
}