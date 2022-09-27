#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
int maxWeight = 0;
int cnt = 1;
// 로프들을 이용한 물체의 최대 중량
// 벡터에다가 무게들을 삽입후 정렬한다
// 끝에서부터 한개씩 고려한다
// 
int main()
{
    cin >> N;

    for (int i=0; i<N; i++)
    {
        int weight;
        cin >> weight;

        v.push_back(weight);
    }

    sort(v.begin(), v.end());

    for (int i=v.size()-1; i>=0; i--)
    {
        if (v[i] * cnt >= maxWeight)
        {    
            maxWeight = v[i] * cnt;  
        }
        cnt++;
    }

    cout << maxWeight;

}