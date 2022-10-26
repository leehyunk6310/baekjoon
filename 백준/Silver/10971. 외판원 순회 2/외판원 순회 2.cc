#include <iostream>
#include <vector>
using namespace std;

// 모든 도시를 순회한다.
// 1번부터 모든 도시를 거쳐서 다시 1번으로 복귀
// 1번부터 방문할수 있는 모든 곳을 확인.
// 길이가 N개인 것은 다시 1번으로 돌아갈 수 있는지 확인
// 길이 갱신
int N;
int W[11][11];
bool visited[11];
int minVal = 1e9;
vector<int> v;

void dfs(int cnt, int sum, int currCity)
{    
    // for (auto vv : v)
        // cout << vv << " ";

    // cout << endl;
    // 모든 곳을 방문한 경우
    if (cnt == N)
    {                        
        if (W[currCity][1] == 0)
            return;

        sum += W[currCity][1];
        // cout << minVal << " " << sum << '\n';
        minVal = min(minVal, sum);
        return;
    }
    
    // 탐색 진행
    for (int i=2; i<=N; i++)
    {
        if (!visited[i] && W[currCity][i] != 0)
        {
            visited[i] = true;
            // v.push_back(i);
            dfs(cnt+1, sum+W[currCity][i], i);
            // v.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N;

    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            cin >> W[i][j];
        }
    }
    
    v.push_back(1);
    dfs(1, 0, 1);
    
    cout << minVal;
    
}