#include <iostream>
using namespace std;

int N, K;
int arr[20] = {0, };
bool visited[20] = {false, };
int answer = 0;

void dfs(int pos, int cnt, int sum)
{
    // 탈출 조건
    if (cnt == N || sum == K)
    {
        answer++;
        return;
    }

    // 다시 탐색하는 경우 pos 이후의 것들만 탐색한다.
    for (int i=pos+1; i<N; i++)
    {
        if (!visited[i] && sum + arr[i] <= K)
        {
            visited[i] = true;
            dfs(i, cnt+1, sum + arr[i]);
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
        cin >> N >> K;
        for (int i=0; i<N; i++)
        {
            cin >> arr[i];
        }

        for (int i=0; i<N; i++)
        {
            visited[i] = true;
            dfs(i, 1, arr[i]);
            visited[i] = false;
        }

        cout << "#" << test_case << " " << answer << '\n';
    }
    
    return 0;
}