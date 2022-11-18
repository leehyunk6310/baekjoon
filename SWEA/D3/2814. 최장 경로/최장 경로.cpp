#include <iostream>
#include <algorithm>
using namespace std;

// N개의 정점, M개의 간선
int arr[11][11] = { 0, };
bool visited[11] = { false, };
int N, M, answer = 0;

void dfs(int node, int cnt)
{
	// 방문가능한 노드를 체크해서 방문한다.
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i] && arr[node][i] == 1)
		{
			visited[i] = true;
			dfs(i, cnt + 1);
			visited[i] = false;
		}
	}
	answer = max(answer, cnt);
}

int main()
{
	int test_case;
	int T;
	cin >> T;

	// 점은 최대 10개이다.
	// 각 점에서 dfs탐색 해야함
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		// 그래프 초기화
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				arr[i][j] = 0;
			}
			visited[i] = false;
		}
		for (int i = 0; i < M; i++)
		{
			int start, dest;

			cin >> start >> dest;
			arr[start][dest] = 1;
			arr[dest][start] = 1;
		}
		answer = 0;

		// 1번 노드부터 dfs탐색
		for (int i = 1; i <= N; i++)
		{
			visited[i] = true;
			dfs(i, 1);
			visited[i] = false;
		}

		cout << "#" << test_case << " " << answer << '\n';
	}

	return 0;
}