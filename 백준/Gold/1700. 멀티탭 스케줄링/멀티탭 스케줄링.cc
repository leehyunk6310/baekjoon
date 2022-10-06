#include <iostream>
using namespace std;

int N, K;   // 구멍 개수, 총 사용 횟수
int schedule[101];
int plugged[101] = {0, };
int answer = 0;
// 현재 멀티탭에 꼽혀잇는 자제품 중 가장 오랫동한 사용하지 않는 것을 찾는다.
int main()
{
    cin >> N >> K;

    for (int i=0; i<K; i++)
    {
        cin >> schedule[i];
    }

    // 스케쥴링한 K개 순서대로 실시
    for (int i=0; i<K; i++)
    {
        bool flag = false;
        // 이미 꼽혀있는 경우 패스
        for (int j=0; j<N; j++)
        {
            if (plugged[j] == schedule[i])
            {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        
        // 빈칸이 있으면 꼽는다
        for (int j=0; j<N; j++)
        {
            if (plugged[j] == 0)
            {
                plugged[j] = schedule[i];
                flag = true;
                break;
            }
        }
        if (flag)
            continue;

        // 빈칸이 필요함        
        int idx = -1;
        int count = -1;
        // 현재 꼽힌 것 중 가장 적게 스케줄된 것을 뺀다.
        for (int j=0; j<N; j++)
        {
            int tmp = 0;
            for (int t=i+1; t<K; t++)
            {
                if (schedule[t] == plugged[j])
                {
                    break;
                }
                tmp++;
            }
            if (tmp > count)
            {
                count = tmp;
                idx = j;
            }
        }

        answer++;
        // 갈아끼운다
        plugged[idx] = schedule[i];
           
    }
    cout << answer;
}