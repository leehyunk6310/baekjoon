#include <iostream>
using namespace std;

int N, M;   // 나무 수 N, 가려가려는 나무 길이 M
int arr[1000001];
int answer = 0;
// 이분 탐색
// high는 꼭대기 low는 바닥으로 설정
// mid = (high + low) / 2로 
// mid에서 잘랐을 때 양이 많으면 low = mid로 갱신하고 반복
// mid에서 잘랐을 때 양이 적으면 high = mid로 갱신하고 반복
int main()
{
    cin >> N >> M;
    int high = 0, low = 0;
    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
        if (arr[i] > high)
            high = arr[i];
    }

    while (high >= low)
    {
        int mid = (high + low) / 2;
        long long sum=0;

        for (int i=0; i<N; i++)
        {
            if (arr[i] > mid)
                sum += arr[i]-mid;
        }
        // 양이 부족하면 더 내려간다.
        if (sum < M)
        {
            high = mid-1;
        }
        else // 양이 충분하면 올라간다.
        {
            answer = mid;
            low = mid+1;
        }
    }

    cout << answer;
}