#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;
int N;
int arr[500001];
int main()
{    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 범위를 위한 변수
    int minVal = 4001, maxVal = -4001;
    // 산술평균을 위한 변수
    double sum = 0;
    // 최빈값을 위한 변수
    // <num, cnt>
    unordered_map<int, int> m; 
    vector<int> v;
    int cnt = 0;

    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
        minVal = (minVal > arr[i] ? arr[i] : minVal);
        maxVal = (maxVal < arr[i] ? arr[i] : maxVal);
        sum += arr[i];
        m[arr[i]]++;
    }

    
    // 산술 평균
    cout << (int)round(sum/N) << "\n";
    // 중앙값
    sort(arr, arr+N);
    cout << arr[N/2] << "\n";
    // 최빈값
    for (auto mm : m)
    {
        if (mm.second > cnt)
            cnt = mm.second;
    }

    for (auto mm : m)
        if (mm.second == cnt)
            v.push_back(mm.first);

    if (v.size() == 1)
        cout << v.front() << "\n";
    else
    {
        sort(v.begin(), v.end());
        cout << v[1] << "\n";
    }
    
    // 범위
    cout << maxVal - minVal << "\n";
}