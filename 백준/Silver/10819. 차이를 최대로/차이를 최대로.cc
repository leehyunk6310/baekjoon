#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 처음과 끝을 제외한 녀석은 2번 쓰인다.
// 순열을 만들어서 적용

int N;
vector<int> v;
int answer = -1e9;

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    
    do
    {
        int val = 0;
        for (int i=0; i<N-1; i++)
        {
           val += abs(v[i] - v[i+1]);
        }
        
        answer = max(answer, val);
    } while (next_permutation(v.begin(), v.end()));
    
    cout << answer;
    
}