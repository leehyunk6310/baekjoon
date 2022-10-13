#include <iostream>
using namespace std;

int N;
char maps[65][65];
string answer = "";
// 분할정복
// 4분할 한다.
// 좌상, 우상, 좌하, 우하 순서로 정복

// 모두 같으면 true, 다른게 있으면 false 반환
bool check(int row, int col, int len)
{
    int start = maps[row][col] - 48;
    for (int i=row; i<row+len; i++)
    {
        for (int j=col; j<col+len; j++)
        {
            if (maps[i][j] - 48 != start)
                return false;
        }
    }
    return true;
}

// 같으면 그대로 문자열 추가, 다르면 괄호 열고 탐색 시작
void solve(int row, int col, int len)
{
    if (check(row, col, len))
    {
        answer += maps[row][col];        
    }
    else
    {
        answer += '(';
        len /= 2;        
        for (int i=0; i<2; i++)
        {
            for (int j=0; j<2; j++)
            {                
                solve(row + len*i, col + len*j, len);                
            }
        }     
        answer += ')';   
    }
}

int main()
{
    cin >> N;
    // 지도 초기화
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cin >> maps[i][j];
        }
    }

    solve(0, 0, N);
    cout << answer;
    
}