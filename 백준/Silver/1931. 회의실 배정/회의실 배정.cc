#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int timeEnd = -1;
int answer = 0;
// 회의를 채택하느냐 안 하느냐
// 회의를 일찍 시작하고 회의 시간이 짧은걸 선택한다.

int main()
{
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int start, ended;
        cin >> start >> ended;
        v.push_back({ended, start});
    }
    // 회의 마치는 시간을 기준으로 sort
    sort(v.begin(), v.end());
    
    for (auto p : v)
    {
        if (p.second >= timeEnd)
        {
            answer++;
            timeEnd = p.first;
        }
    }
    cout << answer;    
}