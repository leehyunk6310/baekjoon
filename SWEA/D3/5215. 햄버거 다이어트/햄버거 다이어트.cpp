#include <iostream>
#include <vector>
using namespace std;

// 칼로리 제한 안에서 가장 높은 점수의 조합중 가장 높은 점수 출력
// 재료 수, 제한 칼로리
int N, L;
// 점수 칼로리
pair<int ,int> p[20];
bool visited[20] = {false, };
int answer = -1;

void dfs(int score, int cal, int pos)
{
    answer = max(answer, score);    
    for (int i=pos+1; i<N; i++)
    {
        if (!visited[i] && cal + p[i].second <= L)
        {
            visited[i] = true;
            dfs(score + p[i].first, cal + p[i].second, i);
            visited[i] = false;
        }
    }
}

int main()
{
    int test_case;
	int T;
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case)
	{
        answer = 0;        

        cin >> N >> L;
        for (int i=0; i<N; i++)
        {
            int score;
            int cal;
            cin >> score >> cal;
            // 점수, 칼로리
            p[i] = {score, cal};
        }

        for (int i=0; i<N; i++)
        {
            if (p[i].second <= L)
            {
                visited[i] = true;
                dfs(p[i].first, p[i].second, i);
                visited[i] = false;
            }
        }

        cout << "#" << test_case << " " << answer << '\n';
    }
    
    
    return 0;
}