#include <iostream>
#include <queue>
using namespace std;

// 사다리를 타고 올라가고, 뱀을 타고 내려간다
// 주사위를 굴린 결과 100번 칸을 넘어가면 이동할 수 없다.
int N, M;   // 사다리, 뱀
int d[101] = {0, }; // 해당 위치까지 이동한 횟수
int arr[101];   // 사다리나 뱀에 의해 이동되는 위치를 표시

int main()
{
    cin >> N >> M;

    // 사다리나 뱀이 없는 경우
    for (int i=1; i<=100; i++)
    {
        arr[i] = i;
    }

    // 사다리나 뱀에 의해서 이동되는 위치를 고려
    for (int i=0; i<N+M; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x] = y;
    }
    
    // 1부터 출발
    d[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        for (int i=1; i<=6; i++)
        {
            int y = x + i;
            if (y > 100) continue;
            // 사다리나 뱀에 의해 갱신된 위치
            y = arr[y];
            if(d[y] == 0)            
            {
                d[y] = d[x] + 1;
                q.push(y);
            }                
        }
        q.pop();
    }

    cout << d[100];

    
}