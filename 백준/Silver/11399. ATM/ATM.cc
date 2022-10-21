#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 필요한 시간의 합의 최솟값을 출력.
// 시간이 적게 걸리는 사람이 먼저 뽑으면 된다.
int N;
vector<int> v;


int main()
{
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int time;
        cin >> time;
        v.push_back(time);
    }

    sort(v.begin(), v.end());

    int tmp = 0;
    int answer = 0;
    for (auto num : v)
    {
        tmp += num;
        answer += tmp;
    }

    cout << answer;
}