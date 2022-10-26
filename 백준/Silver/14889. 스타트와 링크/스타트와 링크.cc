#include <iostream>
#include <vector>
using namespace std;

// 스타트 팀과 링크 팀의 점수 차이가 최소가 되는 값
// 각 팀은 2/N 명으로 이루어진다.

// N/2명을 택한다.
// S에서 점수의 값을 합산한다.
// 나머지의 점수는?
// 차이를 체크한다.
int N;
int S[21][21];
bool visited[21] = {false, };
int minDiff = 1e9;

void dfs(int cnt, int pos)
{    
    // 탈출 조건
    if (cnt == N/2)
    {        
        int currSum = 0;        
        int otherSum = 0;
        
        for (int i=1; i<=N-1; i++)
        {
            for (int j=i+1; j<=N; j++)
            {
                if (visited[i] && visited[j])
                {
                    currSum += S[i][j];
                    currSum += S[j][i];
                }
                else if (!visited[i] && !visited[j])
                {
                    otherSum += S[i][j];
                    otherSum += S[j][i];
                }
            }
        }
        // // 최소 차이값 갱신
        minDiff = min(minDiff, abs(otherSum - currSum));        
               
        return;
    }
    
    for (int i=pos; i<=N; i++)
    {
        if (!visited[i] && i>pos)
        {
            visited[i] = true;
            dfs(cnt+1, i);
            visited[i] = false;
        }
    }
}

int main()
{
    // S 초기화
    cin >> N;
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            cin >> S[i][j];            
        }
    }    

    dfs(0, 0); 

    cout << minDiff;

}