#include <iostream>
#include <queue>
#include <set>
using namespace std;

char board[5][5];
// 상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
set<string> answer;

void dfs(int row, int col, string s)
{
    if (s.size() == 6)
    {
        answer.insert(s);
        return;
    }
    // 4방향 탐색
    for (int i=0; i<4; i++)
    {
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if (nrow>=0 && nrow<5 && ncol>=0 && ncol<5)
        {
            dfs(nrow, ncol, s + board[nrow][ncol]);
        }
    }
}

int main()
{    
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            string str = "";
            str += board[i][j];
            dfs(i, j, str);
        }
    }
    
    cout << answer.size();
}