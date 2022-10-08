#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
int answer[500001]; 
unordered_map<int, int> m;
int main()
{
    
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int num;
        cin >> num;
        m[num]++;
    }
    cin >> M;
    for (int i=0; i<M; i++)
    {
        int num;
        cin >> num;
        answer[i] = m[num];
    }
    for (int i=0; i<M; i++)
    {
        cout << answer[i] << " ";
    }
}