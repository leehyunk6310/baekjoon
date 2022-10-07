#include <iostream>
using namespace std;

int N;
int cost[3];
int sum[1001][3];
int answer = 1e9;
// DP로 푼다
int main()
{
    // R, G, B의 누적 값
    sum[0][0] = 0;
    sum[0][1] = 0;
    sum[0][2] = 0;
    cin >> N;
    for (int i=1; i<=N; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        sum[i][0] = min(sum[i-1][1], sum[i-1][2]) + cost[0];
        sum[i][1] = min(sum[i-1][0], sum[i-1][2]) + cost[1];
        sum[i][2] = min(sum[i-1][0], sum[i-1][1]) + cost[2];
    }

    for (int i=0; i<3; i++)
    {
        answer = min(answer, sum[N][i]);
    }

    cout << answer;
}