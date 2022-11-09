#include <iostream>
using namespace std;

int T, N;
int col[11];    // 각 행에 놓는 열의 위치
int answer = 0;

bool check(int row)
{
    for (int i=0; i<row; i++)
    {
        if (col[i] == col[row] || abs(col[row] - col[i]) == row-i)
            return false;
    }
    return true;
}

void queen(int row)
{
    // 모든 퀸을 다 놓음
    if (row == N)
    {
        answer += 1;
        return;
    }

    for (int i=0; i<N; i++)
    {
        col[row] = i;
        if (check(row))
        {
            queen(row+1);
        }

    }
}

int main()
{
    cin >> T;
    for (int tc=0; tc<T; tc++)
    {        
        cin >> N;
        answer = 0;
        for (int i=0; i<=10; i++)
            col[i] = 0;

        queen(0);

        cout << "#" << tc +1<< " " << answer << "\n";
    }
    
}