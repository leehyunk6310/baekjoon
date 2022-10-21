#include <iostream>
#include <queue>
using namespace std;

// x가 자연수면 추가, 0이면 배열에서 작은 값 출력 및 제거
// priority_queue, 단 넣을때 값이 절댓값이 작은 값이먼저 오도록 

class cmp
{
    public :
    bool operator() (int n1, int n2)
    {        
        // 절댓값이 다른 경우 작은 값이 먼저오도록 한다.
        if (abs(n1) != abs(n2))
            return abs(n1) > abs(n2);
        // 절댓값이 같은 경우
        return n1 > n2;
        
        
    }
};

int N;
priority_queue<int, vector<int>, cmp> pq;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            // 출력
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            // 삽입
            pq.push(x);
        }
    }

    
}