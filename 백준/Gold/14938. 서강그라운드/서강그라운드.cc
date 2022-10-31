#include <iostream>
#include <vector>
using namespace std;
// 와샬 플로이드
int n, m, r;    // 지역, 수색 범위, 길의 개수
vector<vector<int>> maps(101, vector<int>(101, 1e9));
int items[101];
int answer = -1;
int main()
{
    cin >> n >> m >> r;

    for (int i=1; i<=n; i++)
        cin >> items[i];
    
    for (int i=1; i<=n; i++)
    {
        maps[i][i] = 0;
    }

    for (int i=0; i<r; i++)
    {
        int start, dest, length;
        cin >> start >> dest >> length;
        maps[start][dest] = length;
        maps[dest][start] = length;        
    }    

    // 와샬 플로이드로 maps를 갱신한다.
    // 모든 지역에 대하여 착륙 지역을 정한다.
    // 착륙 지역에서 수색 범위 내의 지역들을 선정한다.
    // 아이템을 카운트한다.

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            for (int k=1; k<=n; k++)
            {
                maps[j][k] = min(maps[j][k], maps[j][i] + maps[i][k]);
            }
        }
    }
    
    for (int i=1; i<=n; i++)
    {
        int cnt = items[i];
        for (int j=1; j<=n; j++)
        {
            if (i == j)
                continue;
            if (maps[i][j] <= m)
                cnt += items[j];
        }
        answer = max(answer, cnt);
        
    }
    cout << answer;
    
}