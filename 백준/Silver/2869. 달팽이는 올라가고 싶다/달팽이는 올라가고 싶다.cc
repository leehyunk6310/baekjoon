#include <iostream>
using namespace std;

int A, B, V;

int main()
{
    cin >> A >> B >> V;
    // (V - A)까지 도착하면 다음날 완등
    int cnt;

    if ((V - A) % (A - B) != 0)
        cnt = (V - A) / (A - B) + 1;    
    else
        cnt = (V - A) / (A - B);
    // 다음날 완등이므로 1추가
    cnt++;

    cout << cnt;
}