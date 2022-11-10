#include <iostream>
using namespace std;

int N, M;
int snacks[1000] = {0, };
bool visited[1000] = {false, };
int maxWeight = -1;

void dfs(int cnt, int w)
{
    if (cnt == 2)
    {
        if (w <= M)
            maxWeight = max(maxWeight, w);
        return;
    }
    
    for (int i=0; i<N; i++)
    {
        if (!visited[i] && w+snacks[i] <= M)
        {
            visited[i] = true;
            dfs(cnt+1, w+snacks[i]);
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
        maxWeight = -1;
        // 과자 개수, 최대 무게                
        cin >> N >> M;

        for (int i=0; i<N; i++)
        {
            cin >> snacks[i];
        }

        for (int i=0; i<N; i++)
        {            
            visited[i] = true;
            dfs(1, snacks[i]);
            visited[i] = false;
        }

        cout << "#" << test_case << " " << maxWeight << '\n';
    }
    
    return 0;
}