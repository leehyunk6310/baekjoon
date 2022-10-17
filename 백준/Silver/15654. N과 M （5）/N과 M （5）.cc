#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// backtracking
int N, M;
vector<vector<int>> answer;
vector<int> v;
int arr[9];
bool visited[9] = {false, };


void DFS(int cnt)
{
    // 탈출 조건
    if (cnt == M)
    {
        answer.push_back(v);
        return;
    }

    for (int i=1; i<=N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v.push_back(arr[i]);
            DFS(cnt+1); 
            visited[i] = false;
            v.pop_back();           
        }
        
    }
    
}

int main()
{    
    cin >> N >> M;
    
    for (int i=1; i<=N; i++)
    {
        cin >> arr[i];
    }

    DFS(0);

    sort(answer.begin(), answer.end());

    for (auto v : answer)
    {
        for (auto num : v)
            cout << num << " ";
        cout << '\n';
    }
}