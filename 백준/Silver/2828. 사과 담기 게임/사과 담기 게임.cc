#include <iostream>
using namespace std;

int N, M;
int j;
int l, r;
int dist = 0;

// 스크린 N칸, 바구니 M칸 (M < N)
// 처음에 바구니는 왼쪽 M칸 차지
// 바구니 이동 O, 스크린 경계를 넘어가면 안된다.

int main()
{
    cin >> N >> M;
    cin >> j;
    l = 1; 
    r = M;

    for (int i=0; i<j; i++)
    {
        int pos;
        cin >> pos;

        // pos가 오른쪽에 있는 경우
        // r이 pos가 될 때까지 l, r 을 1씩 증가시킨다.
        if (pos > r)
        {
            while (r != pos)
            {
                r++;
                l++;
                dist++;
            }
        }
        else if (pos < l)
        {
            while (l != pos)
            {
                l--;
                r--;
                dist++;
            }
        }
    }
    cout << dist;
}