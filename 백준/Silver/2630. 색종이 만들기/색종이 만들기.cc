#include <iostream>
using namespace std;

int N;
int paper[129][129];
int blue=0, white=0;

// 현재 정사각형 종이가 같은 색인지 아닌지 check
bool check(int row, int col, int N)
{
    int start = paper[row][col];
    for (int i=row; i<row+N; i++)
    {
        for (int j=col; j<col+N; j++)
        {
            if (paper[i][j] != start)
                return false;
        }
    }
    return true;
}

void solve(int row, int col, int N)
{
    // 같은 색이면 종이수 증가
    if (check(row, col, N))
    {
        if (paper[row][col] == 1)
            blue++;
        else
            white++;
    }
    // 다른 색이 있으면 다시 분할해서 탐색
    // 4개씩 분할된다.
    else
    {
        for (int i=0; i<2; i++)
        {
            for (int j=0; j<2; j++)
            {
                solve(row+i*N/2, col+j*N/2, N/2);
            }
        }
    }

}

int main()
{    
    cin >> N;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cin >> paper[i][j];
        }
    }
    solve(0, 0, N);

    cout << white << '\n' << blue;
}