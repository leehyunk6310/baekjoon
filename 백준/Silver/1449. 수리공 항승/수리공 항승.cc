#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 길이 L인 테이프 무한개
// 좌우 0.5만큼 간격
// 테이프의 최소 개수, 자를 수 없고 겹쳐서 붙이는 것은 가능.
// 첫 위치 - 0.5 부터 L길이만큼 덮는다.
double N, L;
int answer = 0;
vector<int> len;
int main()
{
    cin >> N >> L;    

    for (int i=0; i<N; i++)
    {
        double pos;
        cin >> pos;
        len.push_back(pos);
    }
    sort(len.begin(), len.end());

    double from, to;
    from = len[0]-0.5;
    to = from + L;
    answer++;    

    for (int i=1; i<N; i++)
    {
        // 길이가 to 이하이면 continue
        if (len[i] < to)
            continue;
        // 길이가 to 보다 크면 from과 to를 갱신하고 answer++
        else
        {
            answer++;
            from = len[i] - 0.5;
            to = from + L;
        }        
    }

    cout << answer;
    
}